#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/dp/dynamic_tree_dp.hpp"

#define tests 0
#define fl 0
#define DB 10
struct DP {
  struct X {
    int u, d, dis, ans;
  };
  static X compress(X L, X R) {
    X res;
    res.u = L.u;
    if (R.u != -1) chmax(res.u, L.dis + R.u);
    res.d = R.d;
    if (L.d != -1) chmax(res.d, R.dis + L.d);
    res.dis = L.dis + R.dis;
    res.ans = max(L.ans, R.ans);
    if (L.d != -1 and R.u != -1) chmax(res.ans, L.d + R.u);
    return res;
  }
  static X rake(X L, X R) {
    X res;
    res.u = max(L.u, R.u);
    res.d = L.d;
    if (R.u != -1) chmax(res.d, R.u + L.dis);
    res.dis = L.dis;
    res.ans = max(L.ans, R.ans);
    if (L.u != -1 and R.u != -1) chmax(res.ans, L.u + R.u);
    return res;
  }
};
using X = DP::X;
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  vc<u8> a(N);
  dynamic_tree_dp<DP, decltype(g)> dp(g);
  Z sing = [&](int i) -> X {
    if (not a[i]) return {1, 0, 1, -1};
    return {-1, -1, 1, -1};
  };
  int s = N;
  dp.build(sing);
  INT(Q);
  FOR(Q) {
    CH(op);
    if (op == 'C') {
      INT(i);
      --i;
      a[i] ^= 1;
      s += a[i] ? -1 : 1;
      dp.set(i, sing(i));
    } else {
      print(s == 0 ? -1 : s == 1 ? 0 : dp.prod().ans);
    }
  }
}
#include "YRS/aa/main.hpp"