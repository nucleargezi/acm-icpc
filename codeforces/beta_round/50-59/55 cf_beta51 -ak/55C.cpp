#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  INT(n, m, k);
  FOR(k) {
    INT(x, y);
    if (MIN(x - 1, y - 1, n - x, m - y) < 5) iroha YES();
  }
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"