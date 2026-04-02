#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/Basic.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph<int, 1> g(N);
  vc<int> deg(N);
  FOR(M) {
    INT(f, w, t);
    --f, --t;
    ++deg[t];
    g.add(t, f, w);
  }
  g.build();

  vc<int> in = g.deg_inout().fi;
  vc<ll> c(N);
  queue<int> q;
  FOR(i, N) if (not in[i]) q.eb(i);
  c[N - 1] = 1;
  while (not q.empty()) {
    int n = pop(q);
    for (Z &&e : g[n]) {
      c[e.to] += c[n] * e.w;
      if (not --in[e.to]) q.eb(e.to);
    }
  }
  FOR(i, N - 1) print(deg[i] ? 0 : c[i]);
}
#include "YRS/aa/main.hpp"