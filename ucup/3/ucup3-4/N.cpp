#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N);
  STR(s);
  ll ans = ll(N) * (N + 1) / 2;
  map<char, int> c;
  for (char x : s) ++c[x];
  for (Z [x, y] : c) {
    ans -= ll(y) * (y - 1) / 2;
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"