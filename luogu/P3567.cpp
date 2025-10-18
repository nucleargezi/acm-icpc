#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/online_range_q/range_major_voting.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  major_voting seg(a, Q);
  FOR(Q) {
    INT(l, r);
    --l;
    print(std::max(0, seg.prod(l, r)));
  }
}
#include "YRS/Z_H/main.hpp"