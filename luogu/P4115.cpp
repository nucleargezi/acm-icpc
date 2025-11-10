#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/graph/Tree/dp/dynamic_tree_dp.hpp"

// #define tests
#define tests 0
#define fl 0
#define DB 10
struct DP {
  using X = struct {
    int ans, dis, a, b;
  };
  static constexpr X unit() { return {-1073741823, 0, -1073741823, -1073741823}; }
  static constexpr X compress(X L, X R) {
    X res;
    res.dis = L.dis + R.dis;
    res.a = max(L.a, L.dis + R.a);
    res.b = max(R.b, R.dis + L.b);
    res.ans = max({L.ans, R.ans, L.b + R.a});
    return res;
  }
  static constexpr X rake(X L, X R) {
    X res;
    res.ans = max({L.ans, R.ans, L.a + R.a});
    res.dis = L.dis;
    res.a = max(L.a, R.a);
    res.b = max({L.b, R.a + L.dis});
    return res;
  }
};
void Yorisou() {
  INT(N);
  graph g(N + N - 1);
  vector<int> w(N - 1);
  FOR(i, N - 1) {
    INT(x, y);
    IN(w[i]);
    --x, --y;
    g.add(x, i + N), g.add(y, i + N);
  }
  g.build();
  dynamic_tree_dp<DP, decltype(g)> dp(g, 0);
  dp.build([&](int i) -> DP::X {
    if (i < N) return {0, 0, 0, 0};
    Z r = DP::unit();
    r.dis = w[i - N];
    return r;
  });
  INT(Q);
  int s = N;
  vector<char> vis(N, 1);
  FOR(Q) {
    CH(op);
    if (op == 'A') {
      if (s) print(dp.prod().ans);
      else print("They have disappeared.");
    } else {
      INT(x);
      --x;
      if (vis[x] ^= 1) {
        ++s;
        dp.set(x, {0, 0, 0, 0});
      } else {
        --s;
        dp.set(x, DP::unit());
      }
    }
  }
}
#include "YRS/Z_H/main.hpp"