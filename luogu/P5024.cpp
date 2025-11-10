// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/graph/Tree/dp/dynamic_tree_dp.hpp"

#define tests 0
#define fl 0
#define DB 10
struct DP {
  struct X {
    ll f[2][2];
  };
  static constexpr X compress(const X &L, const X &R) {
    X res{};
    res.f[0][0] = max(L.f[0][0] + R.f[0][0], L.f[0][1] + R.f[1][0]);
    res.f[0][1] = max(L.f[0][0] + R.f[0][1], L.f[0][1] + R.f[1][1]);
    res.f[1][0] = max(L.f[1][0] + R.f[0][0], L.f[1][1] + R.f[1][0]);
    res.f[1][1] = max(L.f[1][0] + R.f[0][1], L.f[1][1] + R.f[1][1]);
    return res;
  }
  static constexpr X rake(const X &L, const X &R) {
    X res{};
    res.f[0][0] = L.f[0][0] + max(R.f[0][0], R.f[0][1]);
    res.f[0][1] = L.f[0][1] + max(R.f[0][0], R.f[0][1]);
    res.f[1][0] = L.f[1][0] + max(R.f[1][0], R.f[1][1]);
    res.f[1][1] = L.f[1][1] + max(R.f[1][0], R.f[1][1]);
    return res;
  }
  static constexpr X make(ll w) {
    X x;
    x.f[0][0] = 0;
    x.f[0][1] = w;
    x.f[1][0] = 0;
    x.f[1][1] = -inf<ll> / 4;
    return x;
  }
};
void Yorisou() {
  INT(N, Q);
  STR(str);
  VEC(int, w, N);
  graph g(N);
  g.read_tree();
  dynamic_tree_dp<DP, decltype(g)> dp(g, 0);
  dp.build([&](int i) -> DP::X { return DP::make(w[i]); });
  ll s = SUM<ll>(w);
  
  FOR(Q) {
    INT(a, x, b, y);
    --a, --b;
    x ^= 1, y ^= 1;
    if ((dp.A[a] == b or dp.A[b] == a) and x and y) {
      print(-1);
      continue;
    }
    dp.set(a, DP::make(x ? 1'000'000'000'000ll + w[a] : -1'000'000'000'000ll));
    dp.set(b, DP::make(y ? 1'000'000'000'000ll + w[b] : -1'000'000'000'000ll));
    Z r = dp.prod();
    dp.set(a, DP::make(w[a]));
    dp.set(b, DP::make(w[b]));
    ll ans = max(r.f[0][0], r.f[0][1]);
    ans -= ll(x + y) * 1'000'000'000'000ll;
    ans = s - ans;
    print(ans);
  }
}
#include "YRS/Z_H/main.hpp"