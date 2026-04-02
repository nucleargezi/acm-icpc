#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/sparse_table/st.hpp"
#include "YRS/ds/monoid/max.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests
using mono = monoid_max<int>;
using Seg = ST<mono>;
using mint = M99;
using P = pair<ll, mint>;
constexpr P INF = {inf<ll>, mint()};
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  VEC(int, b, N);
  INT(K);
  VEC(int, c, K);
  vector<int> v(M + 1, -1);

  FOR(i, N) chmax(v[b[i]], a[i]);
  vector<PII> e;
  FOR(i, 1, M + 1) if (v[i] != -1) e.ep(i, v[i]);
  sort(e);
  
  const int sz = len(e), mx = e.back().fi + 1;
  Seg seg(sz, [&](int i) -> int { return e[i].se; });
  vector<int> cov(mx);
  FOR(i, mx) {
    cov[i] = binary_search([&](int x) -> bool {
      return x == -1 or e[x].fi <= i;
    }, -1, sz) + 1;
  }

  Z merge = [&](P &a, P b) -> void {
    if (b.fi < a.fi) a = b;
    else if (b.fi == a.fi) a.se += b.se;
  };

  vector<std::unordered_map<int, P>> dp(mx);
  dp[0][0] = {0, 1};
  FOR(i, mx - 1) {
    for (Z [hp, v] : dp[i]) {
      int l = cov[i];
      FOR(atk, 1, K + 1) {
        int kl = std::min(mx - 1, i + atk);
        int r = cov[kl];
        int ndp = std::max(hp - atk, seg.prod(l, r));
        if (not dp[kl].contains(ndp)) {
          dp[kl][ndp] = {v.fi + c[atk - 1], v.se};
        } else {
          Z &x = dp[kl][ndp];
          merge(x, {v.fi + c[atk - 1], v.se});
        }
      }
    }
  }

  vector<P> f(M + 1, INF);
  for (Z [hp, c] : dp.back()) f[hp] = c;
  FOR_R(i, M + 1) if (f[i] != INF) {
    FOR(atk, 1, K + 1) {
      Z [ans, ws] = f[i];
      int go = std::max(0, i - atk);
      merge(f[go], P{ans + c[atk - 1], ws});
    }
  }
  Z [ans, ws] = f[0];
  print(ans, ws);
}
#include "YRS/Z_H/main.hpp"