#include "YRS/all.hpp"
#include "YRS/pr/f/exp_miller_factor.hpp"

void Yorisou() {
  setp(9);
  INT(N);
  VEC(ull, p, N);
  Z [ok, t] = exp_miller_factor(p);
  if (ok) print(t);
  else print("oo");
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"