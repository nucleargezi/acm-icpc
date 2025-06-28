#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(a, x, y);
  FOR(i, 100) if (i != a) {
    if (ABS(a - x) > ABS(i - x) and ABS(a - y) > ABS(i - y)) iroha YES();
  }
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"