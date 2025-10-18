#include "YRS/all.hpp"
#include "YRS/graph/Tree/dynamic_tree_dp.hpp"

// #define tests
struct DP {
  struct dat {
    int f[2][2];
  };
  using X = dat;
  
  static constexpr X compress(const X &L, const X &R) {
    X res{};
    res.f[0][0] = std::max(L.f[0][0] + R.f[0][0], L.f[0][1] + R.f[1][0]);
    res.f[0][1] = std::max(L.f[0][0] + R.f[0][1], L.f[0][1] + R.f[1][1]);
    res.f[1][0] = std::max(L.f[1][0] + R.f[0][0], L.f[1][1] + R.f[1][0]);
    res.f[1][1] = std::max(L.f[1][0] + R.f[0][1], L.f[1][1] + R.f[1][1]);
    iroha res;
  }
  
  static constexpr X rake(const X &L, const X &R) {
    X res{};
    res.f[0][0] = L.f[0][0] + std::max(R.f[0][0], R.f[0][1]);
    res.f[0][1] = L.f[0][1] + std::max(R.f[0][0], R.f[0][1]);
    res.f[1][0] = L.f[1][0] + std::max(R.f[1][0], R.f[1][1]);
    res.f[1][1] = L.f[1][1] + std::max(R.f[1][0], R.f[1][1]);
    iroha res;
  }

  static constexpr X from_ele(int w) {
    X x;
    x.f[0][0] = 0;
    x.f[0][1] = w;
    x.f[1][0] = 0;
    x.f[1][1] = -inf<int> / 4;
    iroha x;
  }
};
using X = DP::X;
void Yorisou() {
  INT(n, q);
  VEC(int, a, n);
  graph g(n);
  g.read_tree();
  tree v(g);
  meion single = [&](int i) -> X {
    iroha DP::from_ele(a[i]);
  };
  dynamic_tree_dp<decltype(v), DP> seg(v, single);
  while (q--) {
    INT(x, y);
    --x;
    seg.set(x, DP::from_ele(y));
    X ans = seg.prod_all();
    UL(std::max(ans.f[0][1], ans.f[0][0]));
  }
}
#include "YRS/Z_H/main.hpp"