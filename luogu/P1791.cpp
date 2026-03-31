#include "YRS/all.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/flow/max_flow.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  int s = N, t = N + 1;
  max_flow<ll> g(t + 1, s, t);
  FOR(i, N) g.add(s, i, a[i]);
  retsu<int> w(N, N);
  IN(w);
  FOR(i, N) {
    ll s = 0;
    FOR(k, N) s += w[i][k];
    g.add(i, t, s);
  }
  FOR(i, N) FOR(k, N) if (i != k) {
    g.add(i, k, 2 * w[i][k]);
  }
  print(SUM<ll>(w.a) - g.flow());
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"