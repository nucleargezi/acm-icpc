#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  VEC(int, p, 4);
  INT(a, b);
  ++b;
  sort(p);
  int ans = 0;
  FOR(i, a, b) {
    int s = 0;
    do {
      int x = i;
      FOR(i, 4) x %= p[i];
      s += x == i;
    } while (std::next_permutation(all(p)));
    ans += s >= 7;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"