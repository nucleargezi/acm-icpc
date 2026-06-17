#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/gg/steiner.hpp"

void Yorisou() {
  INT(N, M, K);
  vc<vc<edge_id_w<int>>> g(N);
  vc<T3<int>> es(M);
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    es[i] = {c, a, b};
    g[a].ep(b, i, c);
    g[b].ep(a, i, c);
  }
  VEC(int, s, K);
  FOR(i, K) --s[i];
  if (si(s) <= 15) return print(get<0>(steiner(g, s)));
  
  vc<char> is(N);
  for (int x : s) is[x] = 1;
  vc<int> n;
  FOR(i, N) if (is[i] == 0) n.ep(i);
  int sz = si(n), rs = inf<int>;
  sort(es);
  FOR(m, 1 << sz) {
    fill(all(is), 0);
    FOR(i, sz) if (m >> i & 1) is[n[i]] = 1;
    for (int x : s) is[x] = 1;
    dsu g(N);
    int sm = 0;
    for (var [w, f, t] : es) {
      if (is[f] and is[t] and g.merge(f, t)) sm += w;
      if (sm >= rs) break; 
    }
    bool o = 1;
    FOR(i, 1, K) o &= g[s[i]] == g[s[i - 1]];
    if (o) chmin(rs, sm);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}