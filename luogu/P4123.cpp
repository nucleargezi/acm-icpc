#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(N, M);
  max_flow<int> g(N, 0, N - 1);
  FOR(M) {
    INT(f, t, c);
    --f, --t;
    g.add(f, t, c, c);
  }
  retsu<int> a(N, N, 0);
  FOR(i, N) a[i][i] = inf<int>;
  for (var [f, t, w] : g.gomory_hu()) a[f][t] = a[t][f] = w;
  FOR(i, N) FOR(k, N) FOR(m, N) chmax(a[i][k], min(a[i][m], a[m][k]));
  vc<int> f;
  FOR(i, N) FOR(k, i + 1, N) f.ep(a[i][k]);
  unique(f);
  print(si(f));
}

int main() {
  Yorisou();
  return 0;
}