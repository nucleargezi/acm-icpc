#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(a, b);
  if (a < b) swap(a, b);
  ll d = a * a - b * b;
  print("{}", (d - 1 >> 1) + std::max(d >> 2, 1ll) - 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"