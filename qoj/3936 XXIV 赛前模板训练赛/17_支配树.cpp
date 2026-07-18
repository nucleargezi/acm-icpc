#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dominator.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(5'000'00), gg(g);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
  }
  Z fa(dominator(g, 0));
  FOR(i, 1, N) gg[fa[i]].ep(i);
  vc<int> sz(N);
  Z f = [&](Z &f, int n) -> void {
    sz[n] =1;
    for (int x : gg[n]) f(f, x), sz[n] += sz[x];
  };
  f(f, 0);
  print(sz);
}

int main() {
  Yorisou();
  return 0;
}