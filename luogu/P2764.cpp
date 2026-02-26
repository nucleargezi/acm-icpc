#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/max_flow.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  int s = N << 1, t = s + 1;
  max_flow<int> g(t + 1, s, t);
  FOR(i, N) {
    g.add(s, i, 1);
    g.add(i + N, t, 1);
  }
  FOR(M) {
    INT(x, y);
    --x, --y;
    g.add(x, y + N, 1);
  }
  g.flow();
  dsu un(N);
  for (Z [f, to, flow] : g.get_flow_edges()) {
    if (f == s or to == t) continue;
    if (f >= N) f -= N;
    if (to >= N) to -= N;
    un.merge(f, to);
  }
  Z gp = un.get_group();
  for (Z &v : gp) {
    for (int &x : v) ++x;
    print(v);
  }
  print(len(gp));
}
#include "YRS/aa/main.hpp"