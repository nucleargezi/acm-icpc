#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/nt/bigint/big.hpp"

void Yorisou() {
  string s, t, c;
  bigint a, b;
  IN(s, a, c, t, b, c);
  if (a == b) print(-1);
  else print(a > b ? s : t);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"