#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  LL(a, b, x, y);
  if (a == x and b == y) return Yes();
  if (a == x and ((y & b) == b)) return Yes();
  if (b == y and ((a & x) == x)) return Yes();
  No();
}
#include "YRS/Z_H/main.hpp"