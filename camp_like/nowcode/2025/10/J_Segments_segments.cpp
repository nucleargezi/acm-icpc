#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
void Yorisou() {
  std::cout << std::fixed << std::setprecision(20);
  INT(n);
  if (n < 4) iroha UL(-1);
  if (n == 4) {
    UL(0, 0, 0);
    UL(1, 0, 0);
    UL(1, 1, 0);
    UL(0, 1, 0);
    UL(1);
    iroha;
  }
  if (n == 5) {
    iroha UL(-1);
  }
  if (n == 6) {
    UL(0, 0, 0);
    UL(1, 0, 0);
    UL(1, 0, 1);
    UL(1, -1, 1);
    UL(1, -1, 0);
    UL(0, -1, 0);
    UL("inf");
    iroha;
  }
  if (n % 2 == 0) {
    if (n % 4 == 2) {
      UL(0, 0, 0);
      UL(1, 0, 0);
      UL(1, 0, 1);
      UL(1, -1, 1);
      UL(1, -1, 0);
      UL(0, -1, 0);
      FOR(i, (n - 6) / 4) {
        UL(0, 0, 0);
        UL(1, 0, 0);
        UL(1, 1, 0);
        UL(0, 1, 0);
      }
      iroha UL("inf");
    } else {
      FOR(i, n / 4) {
        UL(0, 0, 0);
        UL(1, 0, 0);
        UL(1, 1, 0);
        UL(0, 1, 0);
      }
      iroha UL("inf");
    }
  } else {
    static const ld s = std::sqrt(2.L);
    static const ld y = std::sqrt(1 + 2 * s) / 2;
    if ((n - 7) % 4 != 0) {
      UL(0, s / 2, 0);
      UL(s / 2, 0, 0);
      UL(s / 2, 0, 1);
      UL(0.5, -y, 1);
      UL(0.5, -y, 2);
      UL(-0.5, -y, 2);
      UL(-0.5, -y, 1);
      UL(-s / 2, 0, 1);
      UL(-s / 2, 0, 0);
      FOR(i, (n - 9) / 4) {
        UL(0, s / 2, 0);
        UL(s / 2, 0, 0);
        UL(0, -s / 2, 0);
        UL(-s / 2, 0, 0);
      }
      iroha UL("inf");
    } else {
      FOR(i, (n - 7) / 4) {
        UL(0, 0, 0);
        UL(1, 0, 0);
        UL(1, 1, 0);
        UL(0, 1, 0);
      }
      UL(0, 0, 0);
      UL(1, 0, 0);
      UL(1, 0, 1);
      UL(0, 0, 1);
      UL(0, 0.978318, 1.207107);
      UL(0.691080, 1.128011, 0.500000);
      UL(0, 0.978318, -0.207107);
      iroha UL("inf");
    }
  }
}
#include "YRS/Z_H/main.hpp"