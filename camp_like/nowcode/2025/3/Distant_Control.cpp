#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, x);
  SV(s, '0');
  meion c = pre_sum(s);
  FOR(i, n - x) {
    if (c[i + x + 1] - c[i] == 0) iroha UL(n);
  }
  FOR(i, n - x + 1) {
    if (c[i + x] - c[i] == x) iroha UL(n);
  }
  UL(c[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"