#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

// #define tests
void Yorisou() {
  INT(a, b, c, d, N);
  VEC(int, v, N);
  YES();
  vector s(std::max(b, d), string(a + c, '.'));
  int x, y;
  if (b & 1) x = b - 1, y = -1;
  else x = b - 1, y = a;
  int r = a * b;
  FOR(i, N) {
    int d = std::min(r, v[i]);
    r -= d, v[i] -= d;
    FOR(d) {
      y += (x & 1) ? -1 : 1;
      if (y >= a) --x, y = a - 1;
      if (y < 0) --x, y = 0;
      s[x][y] = 'a' + i;
    }
    if (not r) break;
  }
  x = 0, y = a - 1, r = c * d;
  FOR(i, N) {
    int d = std::min(r, v[i]);
    r -= d, v[i] -= d;
    FOR(d) {
      y += (x & 1) ? -1 : 1;
      if (y >= a + c) ++x, y = a + c - 1;
      if (y < a) ++x, y = a;
      s[x][y] = i + 'a';
    }
  }
  for (Z &s : s) UL(s);
}
#include "YRS/Z_H/main.hpp"