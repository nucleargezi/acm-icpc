#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  STR(s, t);
  int N = len(s), M = len(t);
  vc<int> c(26);
  FOR(i, N) s[i] -= 'a';
  FOR(i, M) t[i] -= 'a';
  for (int x : s) --c[x];
  for (int x : t) ++c[x];
  for (int x : c) if (x < 0) return Impossible();
  string r;
  FOR(i, 26) if (c[i]) r += string(c[i], i);
  int i = 0, k = 0;
  string ss;
  while (i < N and k < len(r)) {
    if (s[i] <= r[k]) ss += s[i], ++i;
    else ss += r[k], ++k;
  }
  while (i < N) ss += s[i], i++;
  while (k < len(r)) ss += r[k], ++k;
  for (Z &x : ss) x += 'a';
  print(ss);
}
#include "YRS/Z_H/main.hpp"