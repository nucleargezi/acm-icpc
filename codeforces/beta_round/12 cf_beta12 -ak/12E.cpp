#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  vector a(n, vector<int>(n));
  FOR(i, n - 1) FOR(k, n - 1) {
    a[i][k] = (i + k) % (n - 1);
    if (not a[i][k]) a[i][k] = n - 1;
  }
  FOR(i, n - 1) {
    a[n - 1][i] = a[i][n - 1] = a[i][i];
    a[i][i] = 0;
  }
  UL(a);
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