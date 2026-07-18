#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/ds/sl/lict_d.hpp"

void Yorisou() {
  INT(N, Q);
  using DS = lict_d<ll, 0, 1, ll, 18>;
  using np = DS::np;
  ll l = -1'000'000'000, r = -l + 1;
  DS seg(l, r);
  np t = 0;
  FOR(N) {
    LL(l, r, a, b);
    t = seg.add(t, l, r, {a, b});
  }
  FOR(Q) {
    LL(op);
    if (op == 0) {
      LL(l, r, a, b);
      t = seg.add(t, l, r, {a, b});
    } else {
      LL(x);
      ll s = seg.get(t, x).fi;
      if (s == inf<ll>) NO();
      else print(s);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}