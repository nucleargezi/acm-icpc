#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/mcf.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(M, N);
  vvc<int> v(N);
  vvc<int> p(N);
  int tot = 1;
  FOR(i, N) {
    v[i].resize(M + i);
    p[i].resize(M + i);
    IN(v[i]);
    FOR(k, M + i) p[i][k] = tot++, tot++;
  }
  
  int s = 0, t = (M + M + N - 1) * N + 1;
  mcf<int, ll, true> g(t + 1);
  FOR(i, N) {
    FOR(k, M + i) g.add(p[i][k], p[i][k] + 1, 1, -v[i][k]);
    if (i == 0) FOR(k, M) g.add(s, p[i][k], 1, 0);
    else {
      FOR(k, M + i - 1) {
        g.add(p[i - 1][k] + 1, p[i][k], 1, 0);
        g.add(p[i - 1][k] + 1, p[i][k + 1], 1, 0);
      }
    }
  }
  FOR(i, M + N - 1) g.add(p[N - 1][i] + 1, t, 1, 0);
  print(-g.flow(s, t).se);

  g = mcf<int, ll, true>(t + 1);
  FOR(i, N) {
    FOR(k, M + i) g.add(p[i][k], p[i][k] + 1, inf<int>, -v[i][k]);
    if (i == 0) FOR(k, M) g.add(s, p[i][k], 1, 0);
    else {
      FOR(k, M + i - 1) {
        g.add(p[i - 1][k] + 1, p[i][k], 1, 0);
        g.add(p[i - 1][k] + 1, p[i][k + 1], 1, 0);
      }
    }
  }
  FOR(i, M + N - 1) g.add(p[N - 1][i] + 1, t, inf<int>, 0);
  print(-g.flow(s, t).se);
  
  g = mcf<int, ll, true>(t + 1);
  FOR(i, N) {
    FOR(k, M + i) g.add(p[i][k], p[i][k] + 1, inf<int>, -v[i][k]);
    if (i == 0) FOR(k, M) g.add(s, p[i][k], 1, 0);
    else {
      FOR(k, M + i - 1) {
        g.add(p[i - 1][k] + 1, p[i][k], inf<int>, 0);
        g.add(p[i - 1][k] + 1, p[i][k + 1], inf<int>, 0);
      }
    }
  }
  FOR(i, M + N - 1) g.add(p[N - 1][i] + 1, t, inf<int>, 0);
  print(-g.flow(s, t).se);
}
#include "YRS/aa/main.hpp"