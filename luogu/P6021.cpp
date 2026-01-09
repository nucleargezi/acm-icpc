#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/dp/ddp_sub.hpp"

#define tests 0
#define fl 0
#define DB 10
constexpr ll in = inf<ll> >> 2;
struct X {
  ll a, b;
  ll f() const { return min(a, b); }
};
struct DP {
  using X = ::X;
  static X compress(const X &a, const X &b) {
    return {min(a.a, a.b + b.a), min(in, a.b + b.b)};
  }
  static X rake(const X &a, const X &b) {
    return { a.a, min(in, a.b + b.f()) };
  }
  static X fake_rake(const X &a, const X &b) {
    return { in, min(in, a.f() + b.f()) };
  }
};
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  graph g(N);
  g.read_tree();
  vc<int> d = g.deg_array();
  vc<u8> vis(N);
  FOR(i, 1, N) if (d[i] == 1) vis[i] = 1;
  dynamic_tree_dp<DP, decltype(g)> dp(g);
  dp.build([&](int i) -> DP::X { return {a[i], vis[i] ? in : 0}; });
  
  INT(Q);
  FOR(Q) {
    CH(op);
    if (op == 'Q') {
      INT(x);
      --x;
      print(dp.prod_sub(x).f());
    } else {
      INT(x, w);
      --x;
      a[x] += w;
      dp.set(x, {a[x], vis[x] ? in : 0});
    }
  }
}
#include "YRS/aa/main.hpp"