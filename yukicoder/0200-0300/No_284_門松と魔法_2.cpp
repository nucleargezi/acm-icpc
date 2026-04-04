#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"

struct et {
  int a = -1, m = -1, b = -1;
};
bool cmp(const et &a, const et &b) { return a.b > b.b; }
struct dat {
  array<et, 6> a;

  int size() const {
    int s = 0;
    while (s < 6 and a[s].b != -1) ++s;
    return s;
  }

  void ins(et x) {
    int sz = size();
    FOR(i, sz) {
      if (a[i].a == x.a and a[i].m == x.m) {
        chmax(a[i].b, x.b);
        sort(bg(a), bg(a) + sz, cmp);
        return;
      }
    }
    if (sz == 0) return a[0] = x, void();
    FOR(i, sz) {
      if (x.b > a[i].b) {
        FOR_R(k, i + 1, min(sz + 1, 6)) a[k] = a[k - 1];
        a[i] = x;
        return;
      }
    }
    if (sz < 6) a[sz] = x;
  }
};

TE struct seg_t : T {
  using X = T::X;
  using T::op, T::unit;

  vc<X> a;
  int N;

  seg_t(int N) : N(N) { a.assign(N << 1, unit()); }

  void set(int i, X x) {
    a[i += N] = x;
    while (i >>= 1) a[i] = op(a[i << 1], a[i << 1 | 1]);
  }

  X prod(int l, int r) {
    X s = unit();
    l += N, r += N;
    while (l < r) {
      if (l & 1) s = op(s, a[l++]);
      if (r & 1) s = op(s, a[--r]);
      l >>= 1, r >>= 1;
    }
    return s;
  }
};

struct MX {
  using X = dat;
  X op(X a, var b) {
    int sb = b.size();
    FOR(i, sb) a.ins(b.a[i]);
    return a;
  }
  X unit() { return dat(); }
};
using DS = seg_t<MX>;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  for (int &x : a) --x;
  int sz = QMAX(a) + 1;
  DS sa(sz), sb(sz);
  vc<dat> dpl(sz), dpr(sz);
  
  int s = 0;
  for (int x : a) {
    dat nxa;
    nxa.ins({inf<int>, x, 1});
    for (et e : sb.prod(0, x).a) if (e.a != x) {
      nxa.ins({e.m, x, e.b + 1});
    }

    dat nxb;
    nxb.ins({-1, x, 1});
    for (et e : sa.prod(x + 1, sz).a) if (e.a != x) {
      nxb.ins({e.m, x, e.b + 1});
    }
    
    for (et e : nxa.a) dpl[x].ins(e);
    for (et e : nxb.a) dpr[x].ins(e);
    sa.set(x, dpl[x]);
    sb.set(x, dpr[x]);
    for (et e : dpl[x].a) chmax(s, e.b);
    for (et e : dpr[x].a) chmax(s, e.b);
  }
  print(s < 3 ? 0 : s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"