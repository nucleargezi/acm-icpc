#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/gcd_fast.hpp"
#include "YRS/IO/fast_io.hpp"

#define tests
struct mono {
  int l, r;
  ll s, gcd, lcm;
  int tag;

  void upd(int x) {
    gcd = lcm = x;
    s = gcd * (r - l);
  }

  void apply(int x) {
    gcd = gcd_fast<int>(gcd, x);
    lcm = gcd;
    s = gcd * (r - l);
  }

  bool check() const { return gcd == lcm; }
};

#define lp (p << 1)
#define rp (p << 1 | 1)

struct Seg {
  mono dat[4'000'00];

  void update(int p) {
    mono &x = dat[lp], &y = dat[rp];
    dat[p].s = x.s + y.s;
    dat[p].gcd = gcd_fast(x.gcd, y.gcd);
    dat[p].lcm = x.lcm * y.lcm / gcd_fast(x.lcm, y.lcm);
    chmin(dat[p].lcm, inf<int>);
  }

  void down(int p) {
    if (dat[p].tag == -1) return;
    int x = dat[p].tag;
    dat[p].tag = -1;
    dat[lp].tag = dat[rp].tag = x;
    dat[lp].upd(x);
    dat[rp].upd(x);
  }

  void build(int p, int l, int r, const Z f) {
    dat[p].tag = -1;
    dat[p].l = l, dat[p].r = r;
    if (l == r - 1) {
      dat[p] = f(l);
      return;
    }
    int m = (l + r ) >> 1;
    build(lp, l, m, f);
    build(rp, m, r, f);
    update(p);
  }

  ll apply(int p, int l, int r, int ql, int qr, int x) {
    if (r <= ql or l >= qr) return 0;
    if (ql <= l and r <= qr) {
      if (x % dat[p].lcm == 0) return dat[p].s;
      if (dat[p].check()) {
        dat[p].apply(x);
        dat[p].tag = dat[p].gcd;
        return dat[p].s;
      }
      int m = (l + r) >> 1;
      down(p);
      ll res = apply(lp, l, m, ql, qr, x) + apply(rp, m, r, ql, qr, x);
      update(p);
      return res;
    }
    int m = (l + r) >> 1;
    down(p);
    ll res = apply(lp, l, m, ql, qr, x) + apply(rp, m, r, ql, qr, x);
    update(p);
    return res;
  }

  void assign(int p, int l, int r, int ql, int qr, int x) {
    if (r <= ql or l >= qr) return;
    if (ql <= l and r <= qr) {
      dat[p].upd(x);
      dat[p].tag = x;
      return;
    }
    down(p);
    int m = (l + r) >> 1;
    assign(lp, l, m, ql, qr, x), assign(rp, m, r, ql, qr, x);
    update(p);
  }
} seg;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  seg.build(1, 0, N, [&](int i) -> mono {
    return {i, i + 1, a[i], a[i], a[i], -1};
  });
  FOR(Q) {
    INT(op, l, r, x);
    --l;
    if (op == 0) {
      seg.assign(1, 0, N, l, r, x);
    } else {
      print(seg.apply(1, 0, N, l, r, x));
    }
  }
}
#include "YRS/Z_H/main.hpp"