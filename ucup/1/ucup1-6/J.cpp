#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/fenw/fenw.hpp"
#include "YRS/ds/monoid/add.hpp"

#define tests 0
#define fl 0
#define DB 10
using DS = fenw<monoid_add<ll>>;
void Yorisou() {
  INT(N, K, M, Q);
  --K;
  vc<ll> a(N), b(M + 1);
  IN(a, b);
  vc<ll> aa(N, inf<int>), bb(M + 1, inf<int>);
  DS sa(a), sb(b);

  Z get_ring = [&](int l, int r) -> ll {
    if (l > r) swap(l, r);
    if (l == r) return 0;
    ll s = sa.prod(l, r);
    return min(s, sa.prod_all() - s);
  };

  Z get_line = [&](int l, int r) -> ll {
    if (l > r) swap(l, r);
    l -= N, r -= N;
    if (l == r) return 0;
    return sb.prod(l, r);
  };

  FOR(Q) {
    CH(op);
    if (op == 'q') {
      INT(x, y);
      --x, --y;
      ll ans = inf<int>;
      if (x < N and y < N) {
        chmin(ans, get_ring(x, y));
        chmin(ans, get_ring(x, 0) + sb.prod_all() + get_ring(K, y));
        chmin(ans, get_ring(x, K) + sb.prod_all() + get_ring(0, y));
      } else if (x >= N and y >= N) {
        ++x, ++y;
        chmin(ans, get_line(x, y));
        chmin(ans, get_line(x, N) + get_line(y, N + M + 1) + get_ring(0, K));
        chmin(ans, get_line(y, N) + get_line(x, N + M + 1) + get_ring(0, K));
      } else {
        if (x > y) swap(x, y);
        ++y;
        chmin(ans, get_ring(x, 0) + get_line(N, y));
        chmin(ans, get_ring(x, K) + get_line(N + M + 1, y));
      }
      if (ans == inf<int>) print("impossible");
      else print(ans);
    } else if (op == 'c') {
      INT(i);
      --i;
      swap(a[i], aa[i]);
      sa.set(i, a[i]);
    } else {
      INT(i);
      swap(b[i], bb[i]);
      sb.set(i, b[i]);
    }
  }
}
#include "YRS/aa/main.hpp"