#include "YRS/all.hpp"

void Yorisou() {
  INT(a, b);
  a = (a - b + 3) % 3;
  print(a == 0 ? "Drew" : a == 2 ? "Won" : "Lost");
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"