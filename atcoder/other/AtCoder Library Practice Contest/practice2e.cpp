#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/flow/mcf.hpp"

void Yorisou() {
  INT(N, K);
  retsu<int> a(N, N);
  IN(a);
  int A = N + 1, B = N + N * N + 1, C = N + 2 * N * N + 1;
  int s = 0, t = C + N;
  mcf<int, ll, 1> g(t + 1);
  FOR(i, N) g.add(s, i + 1, K, 0);
  FOR(i, N) FOR(k, N) {
    int lp = A + i * N + k, rp = B + i * N + k;
    g.add(i + 1, lp, 1, 0);
    g.add(lp, rp, 1, -a[i][k]);
    g.add(rp, C + k, 1, 0);
  }
  FOR(i, N) g.add(C + i, t, K, 0);

  Z gg = g;
  ll cost = 0, lm = 0;
  for (var [f, c] : g.slope(s, t)) if (chmax(cost, -c)) lm = f;
  gg.flow(s, t, lm);

  vc<string> rs(N, string(N, '.'));
  for (Z &&e : gg.edges) if (e.fl) {
    int f = e.f, t = e.to;
    if (f >= A and f < B and t >= B and t < C) {
      f -= A;
      rs[f / N][f % N] = 'X';
    }
  }
  print(cost);
  FOR(i, N) print(rs[i]);
}

int main() {
  Yorisou();
  return 0;
}