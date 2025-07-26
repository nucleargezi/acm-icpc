#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/PR/prime_sum.hpp"

// #define tests
void Yorisou() {
  LL(n);
  prime_sum<ll> seg(n);
  seg.keis_count();
  UL(seg[n]);
}
#include "MeIoN_Lib/Z_H/main.hpp"