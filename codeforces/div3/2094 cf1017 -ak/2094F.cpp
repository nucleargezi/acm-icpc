#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  INT(n, m, k);
  vector ans(n, vector<int>(m));
  int t{};
  FOR(i, n) FOR(j, m) ans[i][j] = (t++ % k) + 1;
  if (n != 1) FOR(k, m) {
    if (ans[0][k] == ans[1][k]) {
      FOR(i, 0, n, 2) {
        std::ranges::rotate(ans[i], ans[i].begin() + 1);
      }
      break;
    }
  }
  UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","i",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}