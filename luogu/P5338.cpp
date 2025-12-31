#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/treap/treap_monoid.hpp"
#include "YRS/ds/monoid/max.hpp"

#define tests 1
#define fl 0
#define DB 10
using MX = monoid_max<ll>;
using DS = treap_monoid<MX>;
using np = DS::np;
int N, Q;
uint ans = 7, s;
uint rd() { return s = s * 17 + ans, s % N + 1; }
void Yorisou() {
  IN(N, Q, s);
  DS seg;
  vc<ll> dat(N);
  np s = seg.newnode(dat);
  FOR(Q) {
    int x, y;
    x = rd(), y = rd(); 
    --x;
    ll e = dat[x];
    Z [ls, rs] = seg.split_max_right(s, [&](ll x) {
      return x < e;
    });
    Z [del, r] = seg.split(rs, 1);
    dat[x] -= 1ll << 30;
    dat[x] += y;
    e = dat[x];
    Z [l, m] = seg.split_max_right(ls, [&](ll x) {
      return x < e;
    });
    ans = l ? l->sz : 0;
    s = seg.merge(l, seg.newnode(e));
    s = seg.merge(s, m ,r);
    print(ans);
  }
}
#include "YRS/aa/main.hpp"