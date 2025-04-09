#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/primtable.hpp"
#include "MeIoN_Lib/math/prims_test.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, k);
  vector p = primtable(n);
  
  int s{};
  FOR(i, 3, n + 1) {
    if (primetest(i)) {
      int x{upper_bound(p, i - 1 >> 1)};
      s += p[x] + p[x - 1] == i - 1;
    }
  }
  YES(s > k - 1);
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