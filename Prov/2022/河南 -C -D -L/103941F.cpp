#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  if (n == 2 or n == 4) iroha UL(-1);
  if (n & 1) {
    n = ceil(n, 2);
    vector<int> ans(n);
    FOR(i, n) ans[i] = i + 1;
    UL(n);
    UL(ans);
  } else {
    n = n + 2 >> 1;
    vector<int> ans(n);
    FOR(i, n) ans[i] = i + 1;
    ans.erase(ans.begin() + 1);
    UL(n - 1);
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"