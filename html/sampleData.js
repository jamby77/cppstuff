module.exports = [{
        "_id": {
            "$id": "5bf57ee9f2c4606e30542285"
        },
        "action": "PUT",
        "type": "merchandising",
        "subtype": "conditions",
        "oldV": {
            "Id": "1fe",
            "Account": "Stefan Antov",
            "ConditionType": "Applicability",
            "Name": "Petar test",
            "Description": "sample descr",
            "ApiUsers": [{
                "id": "876",
                "text": "santovApi2"
            }],
            "AdvPurchaseRequired": true,
            "TaxApplied": false,
            "Cabins": ["Economy", "PremiumEconomy", "First", "Business", "PremiumBusiness"],
            "EquipmentTypes": [{
                "code": "SSC",
                "name": "AEROSPATIALE - BRITISH AEROSPACE BAC CONCORDE"
            }],
            "RBDsMapping": [{
                "Carrier": "LH",
                "OperatingMarketing": "E",
                "RBDs": ["AB"]
            }],
            "MinimumFlightDuration": 6,
            "MaximumFlightDuration": 12,
            "RequestTime": ["DuringBooking", "AfterBooking", "CheckIn"],
            "FlightRules": [{
                "BothDirections": true,
                "Destinations": [{
                    "Location": "DE",
                    "Type": "Country"
                }],
                "Flights": [{
                    "Vias": [{
                        "Use": [{
                            "Location": "LON",
                            "Type": "City",
                            "ViaType": "Stopover"
                        }]
                    }]
                }],
                "LocationApplication": "Portion",
                "Origins": [{
                    "Location": "SO",
                    "Type": "Country"
                }]
            }]
        },
        "newV": {
            "Id": "1fe",
            "Account": "Stefan Antov",
            "ConditionType": "Applicability",
            "Name": "Petar test",
            "Description": "sample descr",
            "ApiUsers": [{
                "id": "876",
                "text": "santovApi2"
            }],
            "AdvPurchaseRequired": true,
            "TaxApplied": false,
            "Cabins": ["Economy", "PremiumEconomy", "First", "Business", "PremiumBusiness"],
            "EquipmentTypes": [{
                "code": "SSC",
                "name": "AEROSPATIALE - BRITISH AEROSPACE BAC CONCORDE"
            }],
            "RBDsMapping": [{
                "Carrier": "LH",
                "OperatingMarketing": "E",
                "RBDs": ["AB"]
            }],
            "MinimumFlightDuration": 6,
            "MaximumFlightDuration": 12,
            "RequestTime": ["DuringBooking", "AfterBooking", "CheckIn"],
            "FlightRules": [{
                "BothDirections": true,
                "Flights": [{
                    "Vias": [{
                        "Use": [{
                            "Location": "LON",
                            "Type": "City",
                            "ViaType": "Stopover"
                        }]
                    }]
                }],
                "LocationApplication": "Portion",
                "Origins": [{
                    "Location": "SO",
                    "Type": "Country"
                }]
            }]
        },
        "user": "pdzhambazov @vayant.com",
        "id": "5bf57ee9f2c4606e30542285",
        "timestamp": 1542815465
    },
    {
        "_id": {
            "$id": "5bf57389f2c4606e30542284"
        },
        "action": "PUT",
        "type": "merchandising",
        "subtype": "conditions",
        "oldV": {
            "Id": "1fe",
            "Account": "Stefan Antov",
            "ConditionType": "Applicability",
            "Name": "Petar test",
            "Description": "sample descr",
            "ApiUsers": [{
                "id": "876",
                "text": "santovApi2"
            }],
            "AdvPurchaseRequired": true,
            "TaxApplied": false,
            "RequestTime": ["DuringBooking", "AfterBooking", "CheckIn"]
        },
        "newV": {
            "Id": "1fe",
            "Account": "Stefan Antov",
            "ConditionType": "Applicability",
            "Name": "Petar test",
            "Description": "sample descr",
            "ApiUsers": [{
                "id": "876",
                "text": "santovApi2"
            }],
            "AdvPurchaseRequired": true,
            "TaxApplied": false,
            "Cabins": ["Economy", "PremiumEconomy", "First", "Business", "PremiumBusiness"],
            "EquipmentTypes": [{
                "code": "SSC",
                "name": "AEROSPATIALE-BRITISH AEROSPACE BAC CONCORDE"
            }],
            "RBDsMapping": [{
                "Carrier": "LH",
                "OperatingMarketing": "E",
                "RBDs": ["AB"]
            }],
            "MinimumFlightDuration": 6,
            "MaximumFlightDuration": 12,
            "RequestTime": ["DuringBooking", "AfterBooking", "CheckIn"],
            "FlightRules": [{
                "BothDirections": true,
                "Destinations": [{
                    "Location": "MA",
                    "Type": "State"
                }],
                "LocationApplication": "Portion",
                "Origins": [{
                    "Location": "SO",
                    "Type": "Country"
                }]
            }]
        },
        "user": "pdzhambazov@vayant.com",
        "id": "5bf57389f2c4606e30542284",
        "timestamp": 1542812553
    },
    {
        "_id": {
            "$id": "5bf57315f2c460078b39cbb2"
        },
        "action": "POST",
        "type": "merchandising",
        "subtype": "conditions",
        "newV": {
            "Id": "1fe",
            "Account": "Stefan Antov",
            "ConditionType": "Applicability",
            "Name": "Petar test",
            "Description": "sample descr",
            "ApiUsers": [{
                "id": "876",
                "text": "santovApi2"
            }],
            "AdvPurchaseRequired": true,
            "TaxApplied": false,
            "RequestTime": ["DuringBooking", "AfterBooking", "CheckIn"]
        },
        "user": "pdzhambazov@vayant.com",
        "id": "5bf57315f2c460078b39cbb2",
        "timestamp": 1542812437
    }, {
        "_id": {
            "$id": "5bf571f3f2c4607d995bf4a2"
        },
        "action": "DELETE",
        "type": "merchandising",
        "subtype": "conditions",
        "oldV": {
            "Id": "1eo",
            "Account": "Stefan Antov",
            "ConditionType": "ServicePrice",
            "Name": "WEB-3901 Test price",
            "Description": "WEB-3901 Test price",
            "ApiUsers": [{
                "id": "747",
                "text": "santovAPI"
            }],
            "Price": 1,
            "Currency": "EUR",
            "AdvPurchaseRequired": true,
            "TaxApplied": false
        },
        "user": "pdzhambazov@vayant.com",
        "id": "5bf571f3f2c4607d995bf4a2",
        "timestamp": 1542812147
    }, {
        "_id": {
            "$id": "5bf571aaf2c46078d156cdb4"
        },
        "action": "DELETE",
        "type": "merchandising",
        "subtype": "conditions",
        "oldV": {
            "Id": "1f7",
            "Account": "Katrin Bilyanova",
            "ConditionType": "ServicePrice",
            "Name": "test cond price",
            "Description": "test",
            "ApiUsers": [{
                "id": "1182",
                "text": "Katrin"
            }],
            "Price": 10,
            "Currency": "EUR",
            "Refund": "Nonrefundable",
            "AdvPurchaseRequired": true,
            "TaxApplied": false
        },
        "user": "pdzhambazov@vayant.com",
        "id": "5bf571aaf2c46078d156cdb4",
        "timestamp": 1542812074
    }
]