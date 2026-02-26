#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/Basic.hpp"
#include "YRS/g/scc.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph<int, 1> g(N);
  g.read_graph(M);
  Z [c, id] = scc_id(g);
  YES(c == 1);
}
#include "YRS/aa/main.hpp"