#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/math/mod/primitive_root.hpp"

// #define tests
using mint = M17;
void Yorisou() {
  LL(n);
  print("{}", primitive_root_64(n));
}
#include "MeIoN_Lib/Z_H/main.hpp"