#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(t);
  queue<PLL> q;
  FOR(t) {
    LL(op);
    if (op == 1) {
      LL(c, x);
      q.emplace_back(x, c);
    } else {
      LL(k);
      ll ans = 0;
      while (k) {
        meion &[x, c] = q.front();
        ll d = MIN(c, k);
        c -= d;
        k -= d;
        ans += d * x;
        if (not c) q.pop();
      }
      UL(ans);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"