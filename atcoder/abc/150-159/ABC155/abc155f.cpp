#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(PII, dat, N);
  sort(dat);
  vc<int> a(N);
  FOR(i, N) a[i] = dat[i].fi;
  vc<int> b(N + 1);
  b[0] = dat[0].se;
  FOR(i, 1, N) b[i] = dat[i - 1].se ^ dat[i].se;
  b[N] = dat[N - 1].se;

  vc<vc<PII>> g(N + 1);
  FOR(i, M) {
    INT(l, r);
    l = lb(a, l);
    r = lb(a, r + 1);
    g[l].ep(r, i);
    g[r].ep(l, i);
  }
  
  vc<char> vis(N + 1);
  vc<int> s;
  Z f = [&](Z &f, int n) -> int {
    vis[n] = 1;
    int w = b[n];
    for (var [x, c] : g[n]) if (not vis[x]) {
      if (f(f, x)) s.ep(c + 1), w ^= 1;
    }
    return w;
  };
  FOR(i, N + 1) if (not vis[i]) {
    if (f(f, i)) return print(-1);
  }
  sort(s);
  print(si(s));
  print(s);
}

int main() { Yorisou(); }