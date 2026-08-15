#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/sqrt.hpp"
#include "YRS/fps/pow.hpp"
#include "YRS/fps/inte.hpp"
#include "YRS/fps/diff.hpp"

using mint = M99;
void Yorisou() {
  INT(N, K);
  ++N;
  VEC(mint, f, N);
  Z c = f[0];
  f -= exp(inte(inv(sqrt(f))));
  sh(f, N);
  f[0] += 2;
  f[0] -= c;
  f = log(f);
  f[0] += 1;
  print(diff(pow(f, K)));
}

int main() {
  Yorisou();
  return 0;
}