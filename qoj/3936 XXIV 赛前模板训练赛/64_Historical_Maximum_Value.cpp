#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/his_max_add_set.hpp"

using MX = Hismax_set_add<ll>;
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  segl_t<MX> seg(n, [&](int i) { return pair{a[i], a[i]}; });
  FOR(q) {
    LL(op, l, r);
    --l;
    if (op == 1) {
      LL(x);
      seg.apply(l, r, MX::add(x));
    } else if (op == 2) {
      LL(x);
      seg.apply(l, r, MX::set(x));
    } else if (op == 3) {
      print(seg.prod(l, r).fi);
    } else {
      print(seg.prod(l, r).se);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}