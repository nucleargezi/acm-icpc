#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/jen/rasen.hpp"

#define tests
void Yorisou() {
  LL(n);
  vector a = rasen(n, 0);
  FOR(i, n) print("{}", a[i]);
}
#include "MeIoN_Lib/Z_H/main.hpp"