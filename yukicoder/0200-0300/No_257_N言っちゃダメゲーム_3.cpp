#include "YRS/all.hpp"

void Yorisou() {
  INT(N, K);
  int x = (N - 1) % (K + 1);
  while (1) {
    print(x), cout.flush();
    INT(y);
    if (y >= N) break;
    x += K + 1;
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"