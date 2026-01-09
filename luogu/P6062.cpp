#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/max_flow.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  retsu<char> a(N, M);
  FOR(i, N) FOR(k, M) IN(a[i][k]);
  retsu<int> idx(N, M), idy(N, M);
  int cc = 0;
  FOR(i, N) FOR(k, M) if (a[i][k] == '*') {
    if (not i or a[i - 1][k] != '*') idx[i][k] = cc++;
    else idx[i][k] = idx[i - 1][k];
  }
  int ls = cc;
  FOR(i, N) FOR(k, M) if (a[i][k] == '*') {
    if (not k or a[i][k - 1] != '*') idy[i][k] = cc++;
    else idy[i][k] = idy[i][k - 1];
  }

  int s = cc, t = s + 1;
  max_flow<int> g(t + 1, s, t);
  FOR(i, ls) g.add(s, i, 1);
  FOR(i, ls, cc) g.add(i, t, 1);
  FOR(i, N) FOR(k, M) if (a[i][k] == '*') {
    g.add(idx[i][k], idy[i][k], 1);
  }
  print(g.flow());
}
#include "YRS/aa/main.hpp"