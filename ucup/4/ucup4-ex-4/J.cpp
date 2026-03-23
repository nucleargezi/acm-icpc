#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/ds/seg/segdl_def_t.hpp"
#include "YRS/ds/basic/hashmap.hpp"

struct MX {
  struct X {
    ll mx, xo, c;
  };
  static X op(const X &a, const X &b) {
    if (a.mx == -1) return b;
    if (b.mx == -1) return a;
    if (a.mx == b.mx) return {a.mx, a.xo ^ b.xo, a.c + b.c};
    if (a.mx < b.mx) return {b.mx, b.xo, b.c};
    return {a.mx, a.xo, a.c};
  }
  static X unit() { return {-1, 0, 0}; }
};
struct MA {
  using X = int;
  static X op(X l, X r) { return l + r; }
  static X unit() { return 0; }
  static constexpr bool commute = 1;
};
struct AM {
  using MX = ::MX;
  using MA = ::MA;
  using X = MX::X;
  using A = MA::X;
  static constexpr X act(const X &x, const A &a, ll) {
    return {x.mx + a, x.xo, x.c};
  }
};

struct def {
  ll ke(ll n) {
    int t = n & 3;
    if (t == 0) return n;
    if (t == 1) return 1;
    if (t == 2) return n + 1;
    return 0;
  }

  ll prod(ll l, ll r) { return ke(r - 1) ^ ke(l - 1); }

  MX::X dprod(ll l, ll r) { return {0, prod(l, r), r - l}; }
};

using DS = segdl_t<def, AM, 0, ll>;
using np = DS::np;
void Yorisou() {
  LL(N, M, Q);
  VEC(ll, f, M);
  hashmap<set<ll>> se(Q);
  DS seg(0, N);
  np t = seg.newnode();
  int gp = 0;

  Z add = [&](ll l, ll r, ll op = 1) {
    ll sz = r - l;
    if (sz >= N) return;
    ll st = (N - r % N) % N;
    gp += op;
    if (st + sz <= N) {
      t = seg.apply(t, st, st + sz, op);
    } else {
      t = seg.apply(t, st, N, op);
      t = seg.apply(t, 0, sz - (N - st), op);
    }
  };

  Z ins = [&](ll i, ll x) {
    if (x == 0) return;
    set<ll> &s = se[x];
    s.eb(i);
    Z it = s.find(i);
    if (it != s.bg() and next(it) != s.ed()) {
      Z l = prev(it), r = next(it);
      add(*l, *r, -1);
    }
    if (it != s.bg()) add(*prev(it), *it, 1);
    if (next(it) != s.ed()) add(*it, *next(it), 1);
  };

  Z del = [&](ll i, ll x) {
    if (x == 0 ) return;
    Z it = se[x].find(i);
    if (it == se[x].ed()) return;
    if (it != se[x].bg()) add(*prev(it), *it, -1);
    if (next(it) != se[x].ed()) add(*it, *next(it), -1);
    if (it != se[x].bg() and next(it) != se[x].ed())
      add(*prev(it), *next(it), 1);
    se[x].extract(it);
  };

  FOR(i, M) {
    ll x = f[i];
    ins(i, x);
  }
  
  Z out = [&]() {
    if (t->x.mx != gp) print(0, 0);
    else print(t->x.c, t->x.xo);
  };

  out();
  FOR(Q) {
    LL(i, x);
    --i;
    del(i, f[i]);
    ins(i, f[i] = x);
    out();
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"