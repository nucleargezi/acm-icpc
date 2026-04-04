#include "YRS/all.hpp"

void Yorisou() {
  STR(s);
  INT(a, b);
  if (a > b) swap(a, b);
  if (a == b) s.erase(a, 1);
  else s.erase(a, 1), s.erase(b - 1, 1);
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"