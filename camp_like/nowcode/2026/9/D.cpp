#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/fast_lca.hpp"
#include "YRS/ttr/tr.hpp"

void Yorisou() {
  INT(N, Q);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  tr ttr(g, 0);
  fast_lca v(ttr);

  vc<PII> dat(Q);
  vc<int> f;
  FOR(i, Q) {
    INT(x, t);
    --x;
    dat[i] = {x, t};
    f.ep(t + ttr.d[x]);
  }
  unique(f);
  int sz = si(f);
  vc<vc<int>> q(sz);
  FOR(i, Q) {
    var [x, t] = dat[i];
    q[lb(f, t + ttr.d[x])].ep(i);
  }

  string s(Q, '0');
  vc<PII> dp(N);
  vc<int> vs;
  vc<PII> es;
  for (var qi : q) {
    vs.clear();
    for (int i : qi) {
      int x = get<0>(dat[i]);
      Z &[id, op] = dp[x];
      if (op == 0) id = i, op = 1;
      else op = -1;
      vs.ep(x);
    }
    v.tree_compress(vs, es);
    reverse(es);
    for (var [fi, ti] : es) {
      int n = vs[fi], p = vs[ti];
      Z &[i, op] = dp[p];
      if (dp[n].se <= 0 or op == -1) continue;
      if (op == 0) {
        tie(i, op) = dp[n];
      } else if (op == 1) {
        i = 0, op = -1;
      }
    }
    int k = vs[0];
    var [i, op] = dp[k];
    if (op == 1) ++s[i];
    for (int x : vs) dp[x] = {-1, 0};
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}