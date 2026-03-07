#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/tr/inc_mst.hpp"
#include "YRS/ds/heap/erase_heap.hpp"

void Yorisou() {
  INT(N, M);
  VEC(T3<int>, es, M);
  for (Z &[x, y, c] : es) {
    --x, --y, swap(x, c);
  }
  sort(es);
  min_erase_heap<int> q;
  int c = N, s = inf<int>;
  inc_mst<int> ds(N);
  FOR(i, M) {
    Z [w, x, y] = es[i];
    int id = ds.add(x, y, -w, i);
    if (id == -1){
      --c, q.eb(w);
    } else if (id != i) {
      q.pop(get<0>(es[id])), q.eb(w);
    }
    if (c == 1) chmin(s, w - q.top());
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"