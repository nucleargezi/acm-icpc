#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  string mit = "MIT";
  if (n > 5) {
    ll t = 1, bs = 5;
    while (n > bs) ++t, bs *= 5;
    mit += "^" + to_str(t);
  }
  print("{} time", mit);
}
#include "MeIoN_Lib/Z_H/main.hpp"