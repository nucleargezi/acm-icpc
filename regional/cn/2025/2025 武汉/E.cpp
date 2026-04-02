#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  sort(a);
  sort(b);
  if (a == b) return Yes();
  bool f = 0, g = 0;
  FOR(i, N - 1) f |= a[i] + 1 == a[i + 1];
  FOR(i, N - 1) g |= b[i] + 1 == b[i + 1];
  if (f and g) {
    int x = 0, y = 0;
    for (int e : a) ++(e & 1 ? x : y);
    for (int e : b) --(e & 1 ? x : y);
    Yes(not x and not y);
  } else No();
}
#include "YRS/Z_H/main.hpp"