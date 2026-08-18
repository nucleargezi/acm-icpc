#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void slv() {
  INT(N, M, K, pa, pb);
  --pa, --pb;
  vc<int> a(M), b(M);
  for (int &x : a) IN(x);
  for (int &x : b) IN(x);
  vc<int> hs(M);
  map<int, int> cs;
  map<int, PII> dat;
  FOR(K) {
    INT(p, op, c, cc);
    --p, --op;
    hs[op] += c;
    dat[p] = {op, c};
    cs[p] = cc;
  }
  FOR(i, M) if (hs[i] < a[i] + b[i]) return print("impossible");

  int la, ra, lb, rb;
  Z cka = [&](int i) -> bool {
    if (i >= la and i < ra) return 1;
    i += N;
    if (i >= la and i < ra) return 1;
    return 0;
  };
  Z ckb = [&](int i) -> bool {
    if (i >= lb and i < rb) return 1;
    i += N;
    if (i >= lb and i < rb) return 1;
    return 0;
  };
  Z ck = [&](int i) -> bool { return cka(i) and ckb(i); };

  int sz = bina([&](ll sz) -> bool {
    Z aa(a), bb(b);
    ra = pa + N + 1, la = ra - sz;
    rb = pb + N + 1, lb = rb - sz;
    for (var [i, g] : dat) {
      var [op, c] = g;
      if (ck(i)) {
        ;
      } else if (cka(i)) {
        aa[op] -= c;
      } else if (ckb(i)) {
        bb[op] -= c;
      }
    }
    for (var [i, g] : dat) {
      Z [op, c] = g;
      if (ck(i)) {
        if (aa[op] > 0) {
          int d = min(aa[op], c);
          c -= d;
          aa[op] -= d;
        }
        if (bb[op] > 0) bb[op] -= min(bb[op], c);
      }
    }
    return QMAX(aa) <= 0 and QMAX(bb) <= 0;
  }, N, 0);

  ra = pa + N + 1, la = ra - sz;
  rb = pb + N + 1, lb = rb - sz;
  vc<vc<int>> v(M);
  for (var [i, g] : dat) {
    var [op, c] = g;
    v[op].ep(i);
  }
  ll s = 0;

  Z upd = [&](max_heap<PII> &q, int &a, ll w, int c) {
    a -= c;
    s += w * c;
    q.eb(w, c);
    while (a < 0) {
      Z [w, c] = pop(q);
      ll d = min(-a, c);
      s -= w * d;
      c -= d, a += d;
      if (c) q.eb(w, c);
    }
  };
  Z can = [&](var q, ll w) { return q.top().fi > w; };
  Z go = [&](vc<int> v, int a, int b) {
    max_heap<PII> ls, rs;
    if (b == 0) {
      for (int i : v) if (cka(i)) {
        int c = dat[i].se;
        ll w = cs[i];
        upd(ls, a, w, c);
      }
      return;
    }
    if (a == 0) {
      for (int i : v) if (ckb(i)) {
        int c = dat[i].se;
        ll w = cs[i];
        upd(rs, b, w, c);
      }
      return;
    }

    static vc<int> buf;
    buf.clear();
    for (int i : v) {
      int c = dat[i].se;
      ll w = cs[i];
      if (ck(i)) {
        buf.ep(i);
      } else if (cka(i)) {
        upd(ls, a, w, c);
      } else if (ckb(i)) {
        upd(rs, b, w, c);
      }
    }
    sort(buf, [&](int i, int k) { return cs[i] < cs[k]; });
    for (int i : buf) {
      int c = dat[i].se;
      ll w = cs[i];
      if (a) {
        int d = min(c, a);
        upd(ls, a, w, d);
        c -= d;
      }
      if (b and c) {
        int d = min(c, b);
        upd(rs, b, w, d);
        c -= d;
      }
      while (c) {
        bool lc = can(ls, w), rc = can(rs, w);
        if (lc and rc) {
          if (ls.top().fi > rs.top().fi) {
            int d = min(c, ls.top().se);
            upd(ls, a, w, d);
            c -= d;
          } else {
            int d = min(c, rs.top().se);
            upd(rs, b, w, d);
            c -= d;
          }
        } else if (lc) {
          int d = min(c, ls.top().se);
          upd(ls, a, w, d);
          c -= d;
        } else if (rc) {
          int d = min(c, rs.top().se);
          upd(rs, b, w, d);
          c -= d;
        } else break;
      }
    }
  };
  FOR(i, M) if (si(v) and (a[i] or b[i])) {
    go(move(v[i]), a[i], b[i]);
  }
  print(sz - 1, s);
}

int main() { slv(); }