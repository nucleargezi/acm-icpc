#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/lazy_seg_base.hpp"
#include "YRS/ds/a_monoid/min_add.hpp"
#include "YRS/ds/a_monoid/sum_add.hpp"

// #define tests
using MX_mn = a_monoid_min_add<ll>;
using MX_s = a_monoid_sum_add<ll>;
void Yorisou() {
  LL(N, U, R);
  VEC(ll, a, N);
  vector c = pre_sum(a);
  vector<ll> dat(std::max(1ll, N - U + 1));
  FOR(i, 0, N - U + 1) dat[i] = c[i + U] - c[i];
  reverse(dat);
  pop(dat);
  while (len(dat) < N) dat.ep(inf<ll>);
  reverse(dat);

  lazy_seg<MX_mn> seg(dat);
  lazy_seg<MX_s> gg(a);

  Z out = [&]() -> void {
    print(seg.prod_all() > R
              ? gg.prod_all()
              : gg.prod(0,
                    seg.max_right([&](ll x) -> bool { return x > R; }, 1) + 1));
  };
  out();

  INT(Q);
  FOR(Q) {
    LL(p, x);
    --p;
    seg.apply(p, std::min(N, p + U), x - a[p]);
    gg.set(p, x);
    a[p] = x;
    out();
  }
}
#include "YRS/Z_H/main.hpp"