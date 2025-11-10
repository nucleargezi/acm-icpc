#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
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
  VEC(int, w, N);
  graph g(N);
  g.read_tree();
  dynamic_tree_dp<DP, decltype(g)> dp(g, 0);
  dp.build([&](int i) -> DP::X { return DP::make(w[i]); });
  
  ll ans = 0;
  FOR(Q) {
    INT(x, w);
    x ^= ans;
    --x;
    dp.set(x, DP::make(w));
    Z r = dp.prod();
    print(ans = max(r.f[0][0], r.f[0][1]));
  }
}
#include "YRS/Z_H/main.hpp"