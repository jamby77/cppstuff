const sample = require("./sampleData");
const _ = require("underscore");
var stringifyResult = function(result, a, b) {
  if (a) {
    result.old = JSON.stringify(a, null, 2);
  }
  if (b) {
    result.new = JSON.stringify(b, null, 2);
  }
};
var deepDiff = function(a, b) {
  var result = {};
  if ((_.isObject(a) && _.isObject(b)) || (_.isArray(a) && _.isArray(b))) {
    if (_.isEqual(a, b)) {
      result = null;
    } else if (_.isEmpty(a) || _.isEmpty(b)) {
      // any of objects is empty
      stringifyResult(result, a, b);
    } else {
      var keys = _.uniq(_.keys(a).concat(_.keys(b))); // both objects keys
      result = _.filter(
        _.map(keys, function(key) {
          return [key, deepDiff(a[key], b[key])];
        }),
        function(field) {
          return field && field[1];
        }
      );
    }
  } else if (a === b) {
    result = null;
  } else {
    stringifyResult(result, a, b);
  }
  return result;
};
var diffTpl = _.template('<dl><%- field %></dl>' +
    '<dt>Removed:</dt><dd><% if(oldVal){%><pre><%- oldVal %></pre><% } else {%><span class="none">None</span><% } %></dd>' +
    '<dt>Added:</dt><dd><% if(newVal){%><pre><%- newVal %></pre><% } else {%><span class="none">None</span><% } %></dd>');

var formatDiff = function (key, value) {
    var html = "";
    if (_.isArray(value)) {
        // it is nested
        _.each(value, function (value) {
            html += formatDiff(key + " > " + value[0], value[1]);
        });
    } else {
        html = diffTpl({
            field: key,
            oldVal: value.old,
            newVal: value.new
        });
    }

    return html;
};

var helper = {
  generateDescription: function(data) {
    var html = "";
    if (data.action.toUpperCase() === "POST") {
      return "<pre>" + JSON.stringify(data.newV, null, 2) + "</pre>";
    } else if (data.action.toUpperCase() === "DELETE") {
      return "<pre>" + JSON.stringify(data.oldV, null, 2) + "</pre>";
    }
    var diff = _.filter(deepDiff(data.oldV || {}, data.newV || {}), function(
      field
    ) {
      return field && field[1];
    });
    if (diff.length) {
      html +=
        '<table class="table table-striped table-hover table-bordered table-condensed">';
    }

    _.each(diff, function(field) {
      var key = field[0];
      var value = field[1];
      html += "  <tr>";
      html += formatDiff(key, value);
      html += "  </tr>";
    });
    html += "</table>";
    return html;
  }
};

_.each(sample, function(o) {
  const html = helper.generateDescription(o);
  console.log(html);
});
