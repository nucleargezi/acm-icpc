#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/comp_f_ex_minus_1.hpp"
#include "YRS/fps/multi.hpp"

using T = M99;
void Yorisou() {
  LL(n);
  INT(m, x);
  VEC(T, a, m + 1);
  fps f(m + 1), g(f);
  FOR(i, m + 1) f[i] = i;
  f = inte(move(f), a);
  T s = 1;
  FOR(i, m + 1) {
    g[i] = s * ifac(i);
    s *= T(n - i) * T(x);
  }
  g = comp_f_ex_minus_1(move(g));
  T ans = 0;
  FOR(i, m + 1) ans += f[i] * g[i] * fac(i);
  print(ans);
}

int main() { Yorisou(); }
