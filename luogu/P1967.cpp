#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/ttr/hld.hpp"

void Yorisou() {
  INT(N, M);
  vc<T3<int>> es(M);
  for (Z &[f, t, w] : es) {
    IN(f, t, w);
    --f, --t;
    swap(w, f);
  }
  sort(es, greater());
  int t = N;
  dsu g(N << 1);
  vc<vc<int>> v(N << 1);
  vc<int> val(N << 1);
  for (Z [w, a, b] : es) {
    a = g[a], b = g[b];
    if (a != b) {
      g.set(t, a);
      g.set(t, b);
      v[t].ep(a);
      v[t].ep(b);
      val[t] = w;
      ++t;
    }
  }
  FOR(i, t) if (g[i] == i) v[t].ep(i);
  v.resize(t + 1);
  val[t] = -1;
  hld ds(v, t);

  INT(Q);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(val[ds.lca(a, b)]);
  }
}

int main() {
  Yorisou();
  return 0;
}