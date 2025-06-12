#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/discrete_log_fast.hpp"

#define tests
void Yorisou() {
  LL(a, b, m);
  UL(discrete_log(a, b, m));
}
#include "MeIoN_Lib/Z_H/main.hpp"