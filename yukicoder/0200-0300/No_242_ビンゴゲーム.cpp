#include "YRS/all.hpp"

using re = ld;
void Yorisou() {
  INT(N);
  re s = 1;
  FOR(i, 5) s *= re(N - i) / (99 - i);
  setp(10);
  print(s * 12);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"