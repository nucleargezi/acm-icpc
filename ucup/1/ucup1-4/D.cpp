#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  retsu<int> s(N, N);
  FOR(i, N) FOR(k, N) {
    CH(c);
    s[i][k] = c - '0';
  }
  retsu<int> go(N, N, inf<int> / 2);
  FOR(i, N) go[i][i] = 0;
  FOR(i, N) FOR(k, N) if (s[i][k]) go[i][k] = 1;
  FOR(x, N) FOR(i, N) FOR(k, N) {
    chmin(go[i][k], go[i][x] + go[x][k]);
  }
  FOR(i, N) FOR(k, N) go[i][k] &= 1;
  if (go.A == s.A) {
    YES();
    vc<PII> e;
    FOR(i, N) FOR(k, i + 1, N) if (s[i][k]) e.ep(i + 1, k + 1);
    print(len(e));
    for (Z [x, y] : e) print(x, y);
  } else {
    NO();
  }
}
#include "YRS/aa/main.hpp"