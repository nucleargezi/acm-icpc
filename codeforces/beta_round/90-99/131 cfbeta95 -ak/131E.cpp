#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  VEC(PII, a, M);
  vc<int> s(M), c(9);

  map<int, vc<PII>> g;
  Z slv = [&]() {
    for (Z &[_, v] : g) {
      sort(v);
      int n = si(v);
      if (n < 2) continue;
      FOR(i, 1, n - 1) s[v[i].se] += 2;
      s[v[0].se] += 1;
      s[v[n - 1].se] += 1;
    }
    g.clear();
  };
  FOR(i, M) {
    var [x, y] = a[i];
    g[x].ep(y, i);
  }
  slv();
  FOR(i, M) {
    var [x, y] = a[i];
    g[y].ep(x, i);
  }
  slv();
  FOR(i, M) {
    var [x, y] = a[i];
    g[x + y].ep(x, i);
  }
  slv();
  FOR(i, M) {
    var [x, y] = a[i];
    g[x - y].ep(x, i);
  }
  slv();
  FOR(i, M) c[s[i]] += 1;
  print(c);
}

int main() {
  Yorisou();
  return 0;
}