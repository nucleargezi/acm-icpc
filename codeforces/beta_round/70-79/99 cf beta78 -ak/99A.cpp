#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/bigint/big.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int N = len(s);
  bigint x;
  int p = 0;
  FOR(i, N) if (s[i] == '.') x = s.substr(0, i), p = i + 1;
  if (s[p - 2] == '9') return print("GOTO Vasilisa.");
  if (s[p] - '0' > 4) x += 1;
  print(x);
}
#include "YRS/Z_H/main.hpp"