#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, K);
  UL((n - 1) % (K + 1) ? "Win" : "Lose");
}
#include "MeIoN_Lib/Z_H/main.hpp"