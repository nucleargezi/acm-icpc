#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  YES(n != 1 and m != 1 and (n > 2 || m > 2));
}
#include "MeIoN_Lib/Z_H/main.hpp"