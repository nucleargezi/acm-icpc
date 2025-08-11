#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/seaweed_doubling.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  VEC(int, b, n);
  FOR(i, n) --a[i];
  FOR(i, n) --b[i];
  vector<int> res = subunit_monge_dmul(a, b);
  FOR(i, n) ++res[i];
  UL(res);
}
#include "MeIoN_Lib/Z_H/main.hpp"