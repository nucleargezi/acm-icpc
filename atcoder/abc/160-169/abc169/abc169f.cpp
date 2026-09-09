#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using T = M99;

void Yorisou() {
  INT(N, S);
  vc<T> f(S + 1);
  f[0] = 1;
  FOR(i, N) {
    INT(x);
    vc<T> g(f);
    FOR(i, S + 1) g[i] += f[i];
    FOR(k, S + 1 - x) g[k + x] += f[k];
    f.swap(g);
  }
  print(f[S]);
}

int main() { Yorisou(); }