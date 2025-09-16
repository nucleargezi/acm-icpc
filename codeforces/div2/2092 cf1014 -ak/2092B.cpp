#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  STR(s, t);
  int x = 0, y = 0;
  FOR(i, 0, N, 2) x += s[i] == '0';
  FOR(i, 1, N, 2) y += t[i] == '0';
  bool ok = 1;
  ok &= x + y >= ceil(N, 2);
  x = y = 0;
  FOR(i, 1, N, 2) x += s[i] == '0';
  FOR(i, 0, N, 2) y += t[i] == '0';
  ok &= x + y >= N / 2;
  YES(ok);
}
#include "YRS/Z_H/main.hpp"