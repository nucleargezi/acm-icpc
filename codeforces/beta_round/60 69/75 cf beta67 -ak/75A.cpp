#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
int f(int x) {
  int y = 0;
  for (char c : to_s(x)) {
    if (c != '0') y = y * 10 + c - '0';
  }
  return y;
}
void Yorisou() {
  INT(a, b);
  YES(f(a + b) == f(a) + f(b));
}
#include "YRS/Z_H/main.hpp"