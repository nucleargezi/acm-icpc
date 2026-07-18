#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/gg/dag_path_cover.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  int t = 0;
  map<PII, int> mp;
  FOR(i, N) {
    INT(n);
    g[i].resize(n);
    IN(g[i]);
    for (int &x : g[i]) --x, mp[{i, x}] = t++;
  }
  vc<vc<int>> gg(t);
  vc<int> in(t);
  FOR(n, N) for (int x : g[n]) {
    int f = mp[{n, x}];
    for (int y : g[x]) {
      int t = mp[{x, y}];
      ++in[t], gg[f].ep(t);
    }
  }
  vc<int> q;
  FOR(i, t) if (in[i] == 0) q.ep(i);
  FOR(i, si(q)) {
    int n = q[i];
    for (int x : gg[n]) if (--in[x] == 0) q.ep(x);
  }
  vc<int> I(t);
  FOR(i, t) I[q[i]] = i;
  vc<vc<int>> ng(t);
  FOR(n, t) for (int x : gg[n]) ng[I[n]].ep(I[x]);
  print(QMAX(dag_path_cover(ng)) + 1);
}

int main() {
  Yorisou();
  return 0;
}