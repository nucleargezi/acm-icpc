#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  graph g(n);
  g.read_tree<1>();
  ll ans = 0;
  meion f = [&](meion &f, int n, int fa) -> ll {
    ll r = a[n];
    for (meion &&e : g[n]) {
      if (e.to == fa) continue;
      ll x = f(f, e.to, n);
      r += x;
      ans += ABS(x) * e.cost;
    }
    iroha r;
  };
  f(f, 0, -1);
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"