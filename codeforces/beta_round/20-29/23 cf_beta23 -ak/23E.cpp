#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/Big_int.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"

void before() {}

// #define tests
using L = BigInteger;
using node = vector<L>;
void Yorisou() {
  INT(n);
  graph g(n);
  g.read_tree();
  meion f = [&](meion &f, int n, int fa) -> node {
    node dp{0, 1};
    for (meion [_, x, __, id] : g[n]) {
      if (x == fa) continue;
      node g = f(f, x, n);
      node ndp;
      FOR(i, len(dp)) FOR(k, len(g)) {
        while (len(ndp) < i + 1) ndp += L(0);
        chmax(ndp[i], dp[i] * g[k] * k);
        if (i == 1 or k == 1) {
          while (len(ndp) < i + k + 1) ndp += L(0);
          chmax(ndp[i + k], dp[i] * g[k]);
        }
      }
      dp.swap(ndp);
    }
    iroha dp;
  };
  meion dp = f(f, 0, -1);
  L ans;
  FOR(i, len(dp)) chmax(ans, dp[i] * i);
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}