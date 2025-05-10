#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, r);
  VEC(ll, a, n - 1);
  FOR(2) a.insert(a.begin(), 0);
  FOR(2) a += 0;
  chmin(r, n - r);
  set<ll> se;
  FOR(i, n + 3) se += i;
  priority_queue<PLL> q;
  ll ans = 0;
  FOR(i, 1, n + 1) {
    q.emplace(a[i] + a[i + 1], i);
  }
  FOR(r) {
    while (1) {
      meion [val, i] = pop(q);
      if (not se.contains(i)) continue;
      ll k = *se.upper_bound(i);
      if (a[i] + a[k] != val) continue;
      ll pi = *--se.find(i);
      ans += val;
      se -= i;
      se -= k;
      val = a[pi] + a[*se.upper_bound(k)];
      q.emplace(val, pi);
      break;
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"