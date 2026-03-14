#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/tr/inc_mst.hpp"

void Yorisou() {
  INT(N, M);
  inc_mst<int> g(N);
  FOR(i, M) {
    INT(x, y, w);
    print(g.add(x, y, w, i));
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"