#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, s, l, ss);
  YES(n % l or n / l * ss == s);
}
#include "MeIoN_Lib/Z_H/main.hpp"