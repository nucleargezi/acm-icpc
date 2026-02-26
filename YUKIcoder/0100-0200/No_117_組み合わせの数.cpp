#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  STR(s);
  int op = s[0] == 'C' ? 0 : s[0] == 'P' ? 1 : 2;
  s.erase(0, 2);
  s.pop_back();
  int p = s.find(",");
  ll N = stoll(s.substr(0, p)), K = stoll(s.substr(p + 1));
  if (op == 0) print(CC(N, K));
  if (op == 1) print(CC(N, K) * fac(K));
  if (op == 2) print(N != 0 ? CC(K + N - 1, K) : K == 0);
}
#include "YRS/aa/main.hpp"