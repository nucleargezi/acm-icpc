#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  S(s);
  vector<int> L(n), R(n);
  FOR(i, n) L[i] = (i - 1 + n) % n;
  FOR(i, n) R[i] = (i + 1) % n;
  for (int i = 0, d = 0, k = 0, ad = 0; char op : s) {
    --a[i];
    if (op == 'C') {
      ;
    } else if (op == 'S') {
      k = 1;
    } else if (op == 'D') {
      ad += 2;
      k = 1;
    } else if (op == 'R') {
      d ^= 1;
    }
    if (not a[i]) {
      L[R[i]] = L[i];
      R[L[i]] = R[i];
    }
    i = d ? L[i] : R[i];
    a[i] += ad;
    ad = 0;
    if (k) {
      k = 0;
      i = d ? L[i] : R[i];
    }
  }
  FOR(i, n) UL(a[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"