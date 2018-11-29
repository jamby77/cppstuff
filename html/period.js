let A = [1, 1, 1, 1, 1, 1, 1];
// A = [1, 2, -3, 1, 2, -3, 1, 2, -3];
// A = [1, 2, 3, 1, 1, 2, 3, 1];
A = [1, 2, 3, 2, 1, 1, 2, 3, 2, 1, 1, 2];
const n = Math.floor(A.length / 2);
let l = 0;
let h;
let period;
while (++l <= n) {
  h = [];
  period = true;
  for (let i = 0; i < l; i++) {
    h.push(A[i]);
  }
  //   console.log(h);
  for (let k = h.length; k <= A.length; k += h.length) {
    if (!period) {
      break;
    }
    for (let j = 0; j < h.length; j++) {
      //   console.log(k, j);
      const e = A[k + j];

      //   console.log(e);
        if (e !== undefined && e !== h[j]) {
        period = false;
        continue;
      }
    }
  }
  if (period) {
    break;
  }
}

if (period) {
  console.log("Period", h);
} else {
  console.log("Not a period");
}
