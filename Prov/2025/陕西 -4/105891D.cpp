#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = double;
void Yorisou() {
  LL(n);
  REA(V);
  vector<RE> a, b;
  FOR(n) {
    CH(op);
    REA(x);
    (op == '+' ? a : b) += x;
  }
  sort(a,greater());
  sort(b,greater());
  RE ans = 0, t = V, s = 0;
  meion f = [&](meion &f, int x, int y) -> void {
    if (x + y == n) {
      chmax(ans, s);
      iroha;
    }
    meion ct = t, cs = s;
    if (x < len(a)) {
      t += a[x];
      s += t;
      f(f, x + 1, y);
      s = cs;
      t = ct;
    }
    if (y < len(b)) {
      t *= b[y];
      s += t;
      f(f, x, y + 1);
      s = cs;
      t = ct;
    };
  };
  f(f, 0, 0);
  UL(ans / n);
}
#include "MeIoN_Lib/Z_H/main.hpp"