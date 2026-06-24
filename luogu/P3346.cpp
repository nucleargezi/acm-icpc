#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  INT(N, K);
  sam_ex<10> ss;
  VEC(int, s, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }

  vc<int> t;
  FOR(i, N) if (si(g[i]) == 1) t.ep(i);
  
  vc<int> fa(N, -1);
  Z f = [&](Z &f, int n, int p) -> void {
    fa[n] = p;
    int c = 0;
    for (int x : g[n]) if (x != p) f(f, x, n), ++c;
    if (c) return;
    vc<int> buf;
    while (n != -1) buf.ep(s[n]), n = fa[n];
    for (int x = 0; int c : buf) x = ss.add(x, c);
  };
  for (int x : t) f(f, x, -1);
  print(ss.count());
}

int main() {
  Yorisou();
  return 0;
}