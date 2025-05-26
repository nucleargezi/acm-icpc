#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  vector<vector<int>> v(n);
  FOR(n - 1) {
    LL(x, y);
    --x, --y;
    v[x] += y;
    v[y] += x;
  }
  vector<ll> max(n, -inf<ll>), min(n, inf<ll>);
  meion f = [&](meion &f, int n, int fa) -> void {
    for (int x : v[n]) if (x != fa) {
      f(f, x, n);
      ll m{inf<ll>};
      if (a[x] > a[n]) chmin(m, max[x]);
      if (min[x] > a[n]) chmin(m, a[x]);
      chmax(max[n], m);
      m = -inf<ll>;
      if (a[x] < a[n]) chmax(m, min[x]);
      if (max[x] < a[n]) chmax(m, a[x]);
      chmin(min[n], m);
    }
  };
  f(f, 0, 0);
  YES(max[0] != inf<ll> or min[0] != -inf<ll>);
}
#include "MeIoN_Lib/Z_H/main.hpp"