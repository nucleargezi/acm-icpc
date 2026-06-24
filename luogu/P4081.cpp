#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  INT(N);
  sam_ex ss;
  vc<vc<int>> v(4'000'00);
  FOR(i, N) {
    STR(s);
    for (int x = 0; int c : s) x = ss.add(x, c - 'a'), v[x].ep(i);
  }
  vc<vc<int>> g = ss.build_dir_g();
  vc<int> rs(N);
  Z f = [&](Z &f, int n) -> void {
    for (int x : g[n]) {
      f(f, x);
      for (int i = 0, sz = si(v[x]); i < sz and si(v[n]) < 2; ++i) {
        int w = v[x][i], ok = 1;
        for (int x : v[n]) ok &= x != w;
        if (ok) v[n].ep(w);
      }
    }
    if (n and si(v[n]) == 1) {
      int f = ss[n].fa;
      rs[v[n][0]] += ss[n].sz - ss[f].sz;
    }
  };
  f(f, 0);
  for (int x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}