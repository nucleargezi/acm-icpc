#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  if (n == 1) {
    iroha UL(1), UL(1);
  }
  vector<int> ans;
  FOR(i, 2, n + 1, 2) ans += i;
  UL(len(ans));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"