#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/hashmap.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, d);
  VEC(int, a, n);
  constexpr int N = 30003;
  static int f[N];
  FOR(i, n) ++f[a[i]];
  static hash_map<int> dp[N];
  int ans{};
  dp[d][d] = 1;
  FOR(i, N) {
    dp[i].enumerate_all([&](meion x, meion &y) -> void {
      if (not x or not y) iroha;
      y += f[i];
      chmax(ans, y);
      if (i + x < N) chmax(dp[i + x][x], y);
      if (i and x > 1 and i + x - 1 < N) {
        chmax(dp[i + x - 1][x - 1], y);
      }
      if (i and i + x + 1 < N) {
        chmax(dp[i + x + 1][x + 1], y);
      }
    });
  }
  UL(ans - 1);
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