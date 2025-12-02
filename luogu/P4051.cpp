#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/SA.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int N = len(s);
  s += s;
  pop(s);
  SA sa(s);
  string r;
  FOR(i, N + N - 1) if (sa.sa[i] < N) r += s[sa.sa[i] + N - 1];
  print(r);
}
#include "YRS/Z_H/main.hpp"