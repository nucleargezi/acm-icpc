#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/k_presum.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<1004535809>;
void Yorisou() {
  INT(N);
  STR(s);
  mint k = 0;
  for (char c : s) k = k * 10 + c - '0';
  INT(op);
  VEC(mint, f, N);
  if (op == 1) k = -k;
  print(k_presum(f, k));
}
#include "YRS/aa/main.hpp"