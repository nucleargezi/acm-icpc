#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  int ans = 0;
  min_heap<ll> q;
  FOR(i, 3) q.emplace(0);
  while (q.top() != n) {
    meion x = pop(q);
    x = q.top() << 1 | 1;
    q.emplace(MIN(x, n));
    ++ans;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"