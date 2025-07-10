#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(a, b, c, d);
  print("{}", (MIN(a, c) >= MIN(b, d) ? "Gellyfish" : "Flower"));
}
#include "MeIoN_Lib/Z_H/main.hpp"