#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

using re = double;
void Yorisou() {
  INT(N, M, a, b);
  --a, --b;
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  retsu<re> p(N, N);
  FOR(i, N) {
    REAL(x);
    var to = g[i];
    int sz = si(to);
    p[i][i] = x;
    for (int t : to) p[i][t] = (1 - x) / sz;
  }
  Z id = [&](int x, int y) { return x * N + y; };

  retsu<re> v(N * N, N * N);
  FOR(i, N) FOR(k, N) {
    re t = p[i][i] * p[k][k];
    FOR(a, N) FOR(b, N) if (a != i or b != k) {
      v[id(i, k)][id(a, b)] += p[i][a] * p[k][b] / (1 - t);
    }
  }

  vc<re> rs(N), dp(N * N);
  dp[id(a, b)] = 1;
  while (1 - SUM<re>(rs) >= 1e-7) {
    FOR(i, N) rs[i] += dp[id(i, i)], dp[id(i, i)] = 0;
    vc<re> ndp(N * N);
    FOR(a, N * N) FOR(b, N * N) ndp[b] += dp[a] * v[a][b];
    dp.swap(ndp);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}