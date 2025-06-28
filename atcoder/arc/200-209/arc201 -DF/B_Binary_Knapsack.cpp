#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, w);
  vector<max_heap<ll>> q(61);
  FOR(n) {
    LL(x, w);
    q[x].emplace(w);
  }
  ll ans = 0;
  FOR(i, 60) {
    if (w >> i & 1 and len(q[i])) {
      ans += pop(q[i]);
    }
    while (len(q[i]) > 1) {
      meion x = pop(q[i]);
      meion y = pop(q[i]);
      q[i + 1].emplace(x + y);
    }
    if (len(q[i])) q[i + 1].emplace(pop(q[i]));
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"