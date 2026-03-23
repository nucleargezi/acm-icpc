#include "YRS/all.hpp"

constexpr int c[]{1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
void Yorisou() {
  INT(x, k);
  while (x and k) {
    --k;
    int t = x, s = 0;
    while (t) s += c[t % 10], t /= 10;
    x = s;
  }
  print((k & 1) ^ x);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"