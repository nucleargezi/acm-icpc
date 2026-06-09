#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/bcc_e.hpp"

using E = edge_id;
void Yorisou() {
  INT(N, M);
  vc<vc<E>> g(N);
  FOR(i, M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b, i);
    g[b].ep(a, i);
  }
  Z [T, id] = bcc_e(g);
  if (T != 1) return print(0);
  vc<char> ve(M), vs(N);
  Z f = [&](Z &f, int n) -> void {
    for (Z &&e : g[n]) if (not ve[e.id]) {
      ve[e.id] = 1;
      print(n + 1, e + 1);
      if (not vs[e]) vs[e] = 1, f(f, e);
    }
  };
  vs[0] = 1;
  f(f, 0);
}

int main() {
  Yorisou();
  return 0;
}