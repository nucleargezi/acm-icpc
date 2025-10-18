// #include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/poly/fps_sin_cos.hpp"

// #define tests
using mint = M99;
void Yorisou() {
  INT(n, op);
  VEC(mint, a, n);
  UL(not op ? fps_sin(a) : fps_cos(a));
}
#include "MeIoN_Lib/Z_H/main.hpp"