#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dominator.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
  }
  vc<int> fa = dominator(g, 0);
  FOR(i, N) g[i].clear();
  FOR(i, 1, N) g[fa[i]].ep(i);
  vc<int> rs(N, 1);
  Z f = [&](Z &f, int n) -> void {
    for (int x : g[n]) f(f, x), rs[n] += rs[x];
  };
  f(f, 0);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}