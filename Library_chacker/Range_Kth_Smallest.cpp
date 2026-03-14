#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/wave_matrix.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  wave_matrix<int> seg(a);
  FOR(Q) {
    INT(l, r, k);
    print(seg.kth(l, r, k));
  }
}
#include "YRS/Z_H/main.hpp"