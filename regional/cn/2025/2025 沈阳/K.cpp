#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, i);
  --i;
  vector<PLL> s(N), t(N);
  FOR(i, N) IN(s[i], t[i]);
  ll x = 0, y = 0;
  FOR(i, N) x += t[i].fi - s[i].fi, y += t[i].se - s[i].se;
  x >>= 1, y >>= 1;
  x += s[i].fi, y += s[i].se;
  FOR(i, N) if (t[i] == PLL{x, y}) return print(i + 1);
}
#include "YRS/Z_H/main.hpp"