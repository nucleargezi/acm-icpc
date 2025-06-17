#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) a[i] %= 3;
  int c[3]{};
  FOR(i, n) ++c[a[i]];
  UL(c[0] / 2 + MIN(c[1], c[2]));
}
#include "MeIoN_Lib/Z_H/main.hpp"