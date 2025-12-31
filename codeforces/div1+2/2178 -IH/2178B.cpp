#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  int N = len(s), c = std::count(all(s), 'u'), x = 0, y = -inf<int>;
  FOR(i, 1, N - 1) tie(x, y) = pair(max(x, y), s[i] == 'u' ? x + 1 : -inf<int>);
  print(c - max(x, y));
}
#include "YRS/aa/main.hpp"