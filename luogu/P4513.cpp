#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/avl/avl_mono.hpp"
#include "YRS/al/m/max_subarray_sum.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int ,a ,N);
  avl_mono<Max_subarr_sum<ll>> g;
  Z t = g.newnode({all(a)});

  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(l, r);
      if (l > r) swap(l, r);
      --l;
      print(g.prod(t, l, r).mx);
    } else {
      INT(i, x);
      --i;
      t = g.set(t, i, x);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}