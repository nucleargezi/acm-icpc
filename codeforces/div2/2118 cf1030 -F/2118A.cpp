#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  string ans(n, '0');
  FOR(i, k) ans[i]++;
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"