#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/g/dijkstra_fheap.hpp"

void Yorisou() {
  INT(N, M, s);
  --s;
  graph<int, 1> g(N);
  g.sc<1>(M);
  print(dijkstra_fheap_dis<ll, int, 1>(g, s));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"