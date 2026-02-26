#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/dijkstra.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  graph<int, 1> g(N);
  Z add = [&](int f, int t) -> void {
    if (not(t >= 0 and t < N)) return;
    g.add(f, t);
  };
  FOR(i, N) {
    add(i, i + pc(i + 1));
    add(i, i - pc(i + 1));
  }
  g.build();
  int ans = dijkstra(g, 0).fi[N - 1];
  err(dijkstra(g, 0).fi);
  print(ans == inf<int> ? -1 : ans + 1);
}
#include "YRS/aa/main.hpp"