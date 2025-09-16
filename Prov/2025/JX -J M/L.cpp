#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(x, y);
  if (x > 20 and x > y + 1) return Alice();
  if (y > 20 and y > x + 1) return Bob();
  if (x > 29) return Alice();
  if (y > 29) return Bob();
  print("Underway");
}
#include "YRS/Z_H/main.hpp"