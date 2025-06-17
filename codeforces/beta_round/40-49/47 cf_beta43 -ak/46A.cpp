#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  vector<int> ans;
  int x = 0;
  FOR(i, 1, n) {
    x = (x + i) % n;
    ans += x + 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"