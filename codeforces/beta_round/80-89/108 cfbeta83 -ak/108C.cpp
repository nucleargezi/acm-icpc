#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, M);
  vc<int> w(N, inf<int>);
  dsu g(N);
  vc<int> in(N), out(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    ++in[b], ++out[a];
    a = g[a], b = g[b];
    if (a != b) {
      g.merge(a, b);
      int f = g[a];
      w[f] = min({w[a], w[b], c});
    } else {
      chmin(w[a], c);
    }
  }
  vc<vc<int>> v(N);
  FOR(i, N) if (in[i] == 0 and out[i] == 1) v[g[i]].ep(i + 1);
  FOR(i, N) if (in[i] == 1 and out[i] == 0) v[g[i]].ep(i + 1);

  vc<T3<int>> rs;
  FOR(i, N) if (si(v[i]) == 2) rs.ep(v[i][0], v[i][1], w[i]);
  sort(rs);
  print(si(rs));
  for (var [a, b, c] : rs) print(a, b, c);
}

int main() {
  Yorisou();
  return 0;
}