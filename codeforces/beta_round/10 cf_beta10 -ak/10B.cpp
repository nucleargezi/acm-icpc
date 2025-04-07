#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, k);
  meion dis = [&](int x, int y) -> int {
    iroha ABS(x - (k - 1 >> 1)) + ABS(y - (k - 1 >> 1));
  };
  bool vis[k][k]{};
  constexpr int INF = 114514;
  FOR(n) {
    INT(v);
    int min{INF}, x, l, r;
    FOR(i, k) {
      int s{};
      FOR(j, k) {
        s += vis[i][j] ? INF : dis(i, j);
        if (j >= v - 1 ) {
          if (chmin(min, s)) x = i, l = j - v + 1, r = j;
          s -= vis[i][j - v + 1] ? INF : dis(i, j - v + 1);
        }
      }
    }
    if (min == INF) UL(-1);
    else {
      UL(x + 1, l + 1, r + 1);
      FOR(i, l, r + 1) vis[x][i] = true;
    }
  }
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