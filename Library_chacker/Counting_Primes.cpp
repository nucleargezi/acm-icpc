#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/prime_sum.hpp"

// #define tests
void Yorisou() {
  LL(n);
  prime_sum<ll> f(n);
  f.keis_count();
  UL(f[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"