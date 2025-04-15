#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  INT(n);
  VVEC(int, a, n, n);
  set<int> se;
  FOR(i, n) FOR(k, n) se += a[i][k];
  int x{-1};
  FOR(i, 1, n << 1 | 1) {
    if (not se.contains(i)) {
      x = i;
      break;
    }
  }
  vector<int> ans(n << 1);
  ans[0] = x;
  FOR(i, 1, n << 1) {
    ll x{MAX(0ll, i - n)}, y{i - x - 1};
    ans[i] = a[x][y];
  }
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