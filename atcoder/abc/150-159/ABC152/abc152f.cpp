#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<vc<PII>> g(N);
  FOR(i, N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b, i), g[b].ep(a, i);
  }
  vc<ull> d(N);
  Z pr = [&](Z &f, int n, int p) -> void {
    for (var [x, i] : g[n]) if (x != p) {
      d[x] = 1ll << i | d[n], f(f, x, n);
    }
  };
  pr(pr, 0, -1);

  INT(M);
  vc<ull> c(M);
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    c[i] = d[a] ^ d[b];
  }

  ull rs = 0;
  vc<ull> f(1 << M);
  FOR(s, 1 << M) {
    if (s) f[s] = f[s - (1 << lowbit(s))] | c[lowbit(s)];
    rs += (1ll << (N - 1 - pc(f[s]))) * ((pc(s) & 1) ? -1 : 1);
  }
  print(rs);
}

int main() { Yorisou(); }