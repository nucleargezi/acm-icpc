#include "YRS/all.hpp"

using re = ld;
void Yorisou() {
  LL(N);
  setp(10);
  print(re(10000 - N) / 100 / (0.99 * N + re(10000 - N) / 100) * 100);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"