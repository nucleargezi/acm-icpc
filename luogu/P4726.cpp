#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/online_exp.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(mint, f, N);
  online_exp<mint> g;
  FOR(i, N) f[i] = g(f[i]);
  print(f);
}

int main() { Yorisou(); }