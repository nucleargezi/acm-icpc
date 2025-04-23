#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  vector ans(n, string(n, ' '));
  FOR(i, n) FOR(k, n) {
    int f = MIN(i, n - i - 1, k, n - k - 1);
    ans[i][k] = f & 1 ? '.' : '#';
  }
  FOR(i, n) UL(ans[i]);
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