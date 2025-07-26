#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  SV(a, '0');
  print("{}", SUM(a) * (n - 2) + n);
}
#include "MeIoN_Lib/Z_H/main.hpp"