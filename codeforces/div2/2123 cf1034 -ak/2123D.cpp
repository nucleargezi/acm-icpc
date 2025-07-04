#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  SV(s, '0');
  ll sm = SUM(s);
  Alice(sm <= k or k + k > n);
}
#include "MeIoN_Lib/Z_H/main.hpp"