#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using T = M99;

void Yorisou() {
  INT(N, S);
  vc<T> f(S + 1);
  T s = 0;
  FOR(N) {
    INT(x);
    f[0] += 1;
    FOR_R(i, x, S + 1) f[i] += f[i - x];
    s += f[S];
  }
  print(s);
}

int main() { Yorisou(); }