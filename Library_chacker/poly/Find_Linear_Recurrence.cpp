#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint.hpp"
#include "YRS/po/find_line.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, a, N);
  a = find_line(a);
  a.erase(a.begin());
  for (Z &x : a) x = -x;
  print(len(a));
  print(a);
}
#include "YRS/aa/main.hpp"