#include "YRS/all.hpp"
#include "YRS/jen/magic_square.hpp"

void Yorisou() {
  INT(N, y, x, z);
  --x, --y;
  Z a = magic_square{}.run(N);
  z = (z - 1) ^ (a[x][y] - 1);
  FOR(i, N) FOR(k, N) a[i][k] = ((a[i][k] - 1) ^ z) + 1;
  print(a);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"