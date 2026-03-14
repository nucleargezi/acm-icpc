#include "YRS/all.hpp"

void Yorisou() {
  ll s = 0;
  FOR(i, 1, 1000) if (i % 3 == 0 or i % 5 == 0) s += i;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"