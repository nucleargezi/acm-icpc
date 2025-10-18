#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/factors.hpp"

#define tests
void Yorisou() {
  LL(n);
  if (primetest(n)) {
    UL("Prime");
  } else {
    UL(factor(n).back().first);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"