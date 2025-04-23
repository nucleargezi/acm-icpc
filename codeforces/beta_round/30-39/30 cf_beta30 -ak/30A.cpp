#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(a, b, n);
  meion pow = [&](ll x) -> i128 {
    i128 res = 1;
    FOR(n) res *= x;
    iroha res;
  };
  FOR(i, -1000, 1001) {
    if (a * pow(i) == b) iroha UL(i);
  }
  UL("No solution");
}
#include "MeIoN_Lib/Z_H/main.hpp"