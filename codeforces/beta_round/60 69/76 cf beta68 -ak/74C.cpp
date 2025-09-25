#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(x, y);
  print(std::gcd(x - 1, y - 1) + 1);
}
#include "YRS/Z_H/main.hpp"