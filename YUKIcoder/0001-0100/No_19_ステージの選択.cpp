#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/scc.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vc<int> w(N);
  graph<int, 1> g(N);
  int s = 0;
  FOR(i, N) {
    INT(x, f);
    --f;
    w[i] = x;
    g.add(f, i);
    if (f == i) s += x;
  }
  g.build();
  Z [T, id] = scc(g);
  vc<vc<int>> v(T);
  FOR(i, N) v[id[i]].ep(i);
  for (Z &v : v) {
    if (len(v) == 1) {
      s += w[v[0]];
    } else {
      PII mn = inf<PII>;
      for (int x : v) chmin(mn, PII{w[x], x});
      s += mn.fi << 1;
      for (int x : v) if (x != mn.se) s += w[x];
    }
  }
  setp(1);
  print(ld(s) / 2);
}
#include "YRS/aa/main.hpp"