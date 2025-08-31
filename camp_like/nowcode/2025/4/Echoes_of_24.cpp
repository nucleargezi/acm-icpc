#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/IO/fast_io.hpp"
#include "MeIoN_Lib/graph/Tree/tree_monoid.hpp"

// #define tests
constexpr int N = 25;
using bs = bitset<N>;
struct dat {
  bool e, ok;
  int sm;
  vector<PII> seg;
  
  bool keis() {
    if (not ok) iroha 0;
    bs dp{}, ndp{};
    --seg[0].second;
    dp[seg[0].first] = 1;
    for (meion [x, c] : seg) {
      if (x == 1) {
        while (c--) {
          ndp = dp << 1;
          if (ndp == dp) break;
          dp |= ndp;
        }
      } else {
        while (c--) {
          ndp.reset();
          for (int i = dp._Find_first(); i < N; i = dp._Find_next(i)) {
            if (i + x < N) {
              ndp.set(i + x);
            }
            if (i * x < N) {
              ndp.set(i * x);
            }
          }
          if (ndp.none()) {
            ++seg[0].second;
            iroha 0;
          }
          dp = ndp;
        }
      }
    }
    ++seg[0].second;
    iroha dp[24];
  }
};
struct mono {
  using X = dat;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    if (x.e) iroha y;
    if (y.e) iroha x;
    if (x.ok and y.ok and x.sm + y.sm <= 24) {
      X ret{0, 1, x.sm + y.sm, x.seg};
      for (meion [x, y] : y.seg) {
        if (ret.seg.back().first == x) ret.seg.back().second += y;
        else ret.seg.emplace_back(x, y);
      }
      iroha ret;
    }
    iroha {0, 0, 0, {}};
  }
  static constexpr X from_ele(int x) {
    if (x > 24) iroha {0, 0, 0, {}};
    iroha {0, 1, x != 1 ? x : 0, {{x, 1}}};
  }
  static constexpr X unit() { iroha {1}; }
  static constexpr bool commute = false;
};
void Yorisou() {
  LL(n, q);
  VEC(int, a, n);
  graph g(n);
  g.read_tree();
  tree v(g);
  tree_monoid<decltype(v), mono> seg(v, [&](int i) { iroha mono::from_ele(a[i]); });
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(x, y);
      --x, --y;
      UL(seg.prod_path(x, y).keis());
    } else {
      LL(x, v);
      --x;
      seg.set(x, mono::from_ele(v));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"