#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/chirp_z_transfrom.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n, c, m);
  VEC(mint, a, n);
  UL(chirp_z_transform<mint>(a, c, m));
}
#include "MeIoN_Lib/Z_H/main.hpp"