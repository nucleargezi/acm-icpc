#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/bs.hpp"

void Yorisou() {
  INT(N, M, K);
  bs a(K), b(K);
  FOR(N) {
    INT(x);
    a.set(x - 1);
  }
  FOR(M) {
    INT(x);
    b.set(x - 1);
  }
  INT(Q);
  FOR(i, Q) {
    print((a & b).count());
    b <<= 1;
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"