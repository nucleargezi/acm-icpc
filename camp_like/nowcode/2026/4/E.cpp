#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/johnson.hpp"

using re = ld;
void Yorisou() {
  INT(N, M, Q);
  vc<vc<edge_w<int>>> g(N);
  vc<T3<int>> es(M);
  for (Z &[a, b, c] : es) {
    IN(a, b, c);
    --a, --b;
    g[a].ep(b, c);
  }
  Z d = johnson<ll>(g);
  FOR(Q) {
    INT(id, k);
    --id;
    re s = 0;
    var [a, b, c] = es[id];
    FOR(i, M) {
      Z [f, t, w] = es[i];
      if (i == id) w = k;
      s = max(s, min(d[t][f], d[t][a] + d[b][f] + k) / re(w));
    }
    print(s);
  }
}

int main() {
  setp(12);
  INT(T);
  FOR(T) Yorisou();
  return 0;
}