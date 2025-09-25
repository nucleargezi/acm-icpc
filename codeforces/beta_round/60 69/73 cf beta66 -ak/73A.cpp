#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  VEC(int, a, 3);
  FOR(i, 3) --a[i];
  sort(a);
  INT(K);
  vector<int> g(3);
  Z [x, y] = divmod(K, 3);
  int d = std::min(a[0], x);
  g[0] = d + 1;
  y += x - d;
  x += y / 2, y &= 1;
  d = std::min(a[1], x);
  g[1] = d + 1;
  y += x - d;
  x += y;
  g[2] = std::min(a[2], x) + 1;
  print(1ll * g[0] * g[1] * g[2]);
}
#include "YRS/Z_H/main.hpp"