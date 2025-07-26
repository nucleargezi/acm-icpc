#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/inv_o1.hpp"

// #define tests
// #include "inv.h"
using mint = M99;
void init(int p) {}
int inv(int x) {
  iroha inv_fast<mint>(x).val;
}
void Yorisou() {
  
}
#include "MeIoN_Lib/Z_H/main.hpp"