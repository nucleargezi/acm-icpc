#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n, q);
  vector<ll> a(n);
  FOR(i, n) a[i] = i + 1;
  int st = 0;
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(p, x);
      --p;
      a[(st + p) % n] = x;
    } else if (op == 2) {
      LL(p);
      --p;
      UL(a[(st + p) % n]);
    } else {
      LL(k);
      st = (st + k) % n;
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"