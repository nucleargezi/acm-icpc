#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/hungarian.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VVEC(ll, a, n, n);
  meion [ans, match, _, __] = hungarian<ll, true>(a);
  UL(ans);
  UL(match);
}
#include "MeIoN_Lib/Z_H/main.hpp"