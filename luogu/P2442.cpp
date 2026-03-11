#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/static_range_group.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/st/st_range_prod.hpp"
#include "YRS/al/m/minmax.hpp"

void Yorisou() {
  INT(N, Q);
  vc<PII> a(N);
  vc<PII> v[100];
  FOR(i, N) IN(a[i].fi);
  FOR(i, N) {
    IN(a[i].se);
    v[a[i].fi - 1].ep(i, a[i].se);
  }

  vc<T3<int>> qs(Q), q[3];
  FOR(i, Q) {
    INT(op, l, r);
    --op, --l;
    qs[i] = {op, l, r};
    q[op].ep(i, l, r);
  }
  vc<int> sum(Q), cnt(Q);

  st_range_prod_t<monoid_minmax<int>> st(
      N, [&](int i) { return PII {a[i].fi, a[i].fi}; });
  for (Z &&[i, l, r] : q[2]) {
    Z [mn, mx] = st.prod(l, r);
    sum[i] = mx - mn;
  }

  vc<int> dat(N);
  static_range_group<monoid_add<int>> ds;
  FOR(val, 1, 101) {
    if (v[val - 1].empty()) continue;
    fill(all(dat), 0);
    for (Z &&[k, c] : v[val - 1]) dat[k] = c;
    ds.build(dat);
    for (Z &&[i, l, r] : q[0]) {
      int c = ds.prod(l, r);
      cnt[i] += c;
      sum[i] += c * val;
    }
    for (Z &&[i, l, r] : q[1]) {
      int c = ds.prod(l, r);
      if (chmax(sum[i], c)) cnt[i] = val;
    }
  }

  FOR(i, Q) {
    int op = get<0>(qs[i]);
    if (op == 0) print((ld)sum[i] / cnt[i]);
    if (op == 1) print(cnt[i]);
    if (op == 2) print(sum[i]);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"