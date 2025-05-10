#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  string ans;
  FOR(26) {
    LL(x);
    ans += 'a' + x - 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"