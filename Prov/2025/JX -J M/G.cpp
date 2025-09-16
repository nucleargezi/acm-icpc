#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  LL(N);
  if (N < 5 and N != 3) return print(-1);
  Z [x, y] = divmod<ll>(N, 3);
  print(x - (y == 1));
}
#include "YRS/Z_H/main.hpp"