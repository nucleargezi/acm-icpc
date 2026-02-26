#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  vc<int> psb{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  INT(N);
  FOR(N) {
    INT(a, b, c, d);
    STR(op);
    vc<int> nx;
    if (op == "NO") {
      for (int x : psb) if (x != a and x != b and x != c and x != d) nx.ep(x);
    } else {
      for (int x : psb) if (x == a or x == b or x == c or x == d) nx.ep(x);
    }
    psb.swap(nx);
  }
  print(psb[0]);
}
#include "YRS/aa/main.hpp"