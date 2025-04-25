#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, rs, s);
  --rs, --s;
  vector<vector<ll>> v(n);
  FOR(i, n) {
    if (i == rs) continue;
    LL(f);
    --f;
    v[f] += i;
    v[i] += f;
  }
  vector<ll> ans(n, -1);
  meion f = [&](meion &f, ll n, ll fa) -> void {
    for (ll x : v[n]) {
      if (x == fa) continue;
      ans[x] = n + 1;
      f(f, x, n);
    }
  };
  f(f, s, -1);
  ans.erase(ans.begin() + s);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"