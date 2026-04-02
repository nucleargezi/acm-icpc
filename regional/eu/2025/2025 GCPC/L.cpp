#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(t);
  print(binary_search([&](int rs) -> bool {
    int wk = t - rs;
    int nd = wk > 9 * 60 ? 45 : wk > 6 * 60 ? 30 : 0;
    if (wk > 600) return false;
    return rs >= nd;
  }, 1440, -1));
}
#include "YRS/Z_H/main.hpp"