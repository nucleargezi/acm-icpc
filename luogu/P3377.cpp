#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/ds/heap/merge.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = merge_heap<PII, 1, 0>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  DS heap;
  vc<np> q(N, nullptr);
  FOR(i, N) {
    INT(x);
    q[i] = heap.push(q[i], {x, i});
  }
  dsu g(N);
  vc<u8> vis(N);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y);
      --x, --y;
      if (vis[x] or vis[y]) continue;
      x = g[x], y = g[y];
      if (not g.merge(x, y)) continue;
      q[g[x]] = heap.merge(q[x], q[y]); 
    } else {
      INT(x);
      --x;
      if (vis[x]) print(-1);
      else {
        x = g[x];
        Z [val, id] = heap.top(q[x]);
        print(val);
        vis[id] = 1;
        q[x] = heap.pop(q[x]);
      }
    }
  }
}
#include "YRS/aa/main.hpp"