#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/prims_test.hpp"

// #define tests
void Yorisou() {
  ll n;
  char s[]{'N', 'Y'};
  while (IN(n)) {
    print("{}", s[primetest(n)]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"