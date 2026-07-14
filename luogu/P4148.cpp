#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/range/rec_sum_point_add.hpp"

void Yorisou() {
  INT(N);
  dyn_grid_abel<Add<int>, int> seg(N);
  int ls = 0;
  for (int op; IN(op), op != 3; ) {
    if (op == 1) {
      INT(x, y, w);
      x ^= ls, y ^= ls, w ^= ls;
      seg.add(x, y, w);
    } else {
      INT(l, c, r, d);
      l ^= ls, r ^= ls, c ^= ls, d ^= ls;
      print(ls = seg.prod(l, r, c, d));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}