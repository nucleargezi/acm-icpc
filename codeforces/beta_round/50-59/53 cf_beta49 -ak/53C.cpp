#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  vector<int> ans;
  FOR(i, n >> 1) {
    ans += i + 1;
    ans += n - i;
  }
  if (n & 1) ans += n + 1 >> 1;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"