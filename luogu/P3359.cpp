#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/gg/bs.hpp"

void Yorisou() {
  INT(N);
  VEC(T3<int>, es, N - 1);
  VEC(int, I, N - 1);
  for (Z &[a, b, c] : es) --a, --b;
  for (int &x : I) --x;
  vc<map<int, int>> se(N);
  FOR(i, N) se[i][0] = 1;
  vc<ll> rs(N);
  dsu g(N);
  vc<int> dat(N);
  vc<vc<int>> v(N);
  FOR(i, N) v[i].ep(i);
  ll s = 0;
  FOR_R(i, N - 1) {
    int ei = I[i];
    Z [a, b, c] = es[ei];
    int aa = g[a], bb = g[b], sa = si(v[aa]), sb = si(v[bb]);
    c ^= dat[a] ^ dat[b];
    if (sa < sb) swap(a, b), swap(aa, bb), swap(sa, sb);
    Z &f = se[aa];
    for (var [x, y] : se[bb]) s += 1ll * y * (f.contains(x ^ c) ? f[x ^ c] : 0);
    for (var [x, y] : se[bb]) f[x ^ c] += y;
    se[bb].clear();
    for (int x; sb--; ) x = pop(v[bb]), dat[x] ^= c, v[aa].ep(x);
    g.set(aa, bb);
    rs[i] = s;
  }
  for (ll s : rs) print(s);
}

int main() {
  Yorisou();
  return 0;
}