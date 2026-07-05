#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  vc<int> sz(N, 1);
  Z f = [&](Z &f, int n, int p) -> mint {
    mint rs = 1;
    for (int x : g[n]) if (x != p) {
      rs *= f(f, x, n);
      sz[n] += sz[x];
    }
    if (a[n]) rs += mint(2).pow(sz[n] - 1);
    return rs;
  };
  print(f(f, 0, 0));
}

int main() {
  Yorisou();
  return 0;
}