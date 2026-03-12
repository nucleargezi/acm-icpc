#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  STR(a, b);
  int s = 0;
  FOR(i, N) s += a[i] != b[i];
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"