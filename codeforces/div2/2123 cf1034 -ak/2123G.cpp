#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/Z_H/FH.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  INT(n, m, q);
  VEC(int, a, n);
  vector<int> es;
  for (int i = 1; i * i <= m; ++i) {
    es += i, es += m / i;
  }
  unique(es);
  int N = len(es);
  vector<int> c(N), R(N);
  for (int i = 0; i < N; ++i) {
    int x = es[i];
    R[i] = (m / x) - 1;
    int cc = 0;
    for (int k = 1; k < n; ++k) {
      if (a[k] % x < a[k - 1] % x) cc++;
    }
    c[i] = cc;
  }
  for (int i = 0; i < q; ++i) {
    INT(op);
    if (op == 1) {
      INT(p, go);
      --p;
      int pr = a[p];
      for (int i = 0; i < N; ++i) {
        int x = es[i];
        if (p > 0) {
          int A = a[p - 1] % x, B = pr % x, C = go % x;
          int ba = (B < A), ca = (C < A);
          c[i] += (ca - ba);
        }
        if (p + 1 < n) {
          int A = a[p + 1] % x, B = pr % x, C = go % x;
          int ab = (A < B), ac = (A < C);
          c[i] += (ac - ab);
        }
      }
      a[p] = go;
    } else {
      INT(k);
      k = lower_bound(es, GCD(k, m));
      YES(c[k] <= R[k]);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"