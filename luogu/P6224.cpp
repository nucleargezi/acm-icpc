#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

struct kdt {
  using it = vc<T3<int>>::iterator;
  struct node;
  using np = node *;
  struct node {
    int x, y, l, r, c, d;
    ll nor;
    int id, mn_id;
    np ls{}, rs{};
    void upd() {
      l = r = x, c = d = y;
      nor = abs(x) + abs(y);
      mn_id = id;
      if (ls) {
        chmin(l, ls->l), chmax(r, ls->r);
        chmin(c, ls->c), chmax(d, ls->d);
        chmax(nor, ls->nor);
        chmin(mn_id, ls->mn_id);
      }
      if (rs) {
        chmin(l, rs->l), chmax(r, rs->r);
        chmin(c, rs->c), chmax(d, rs->d);
        chmax(nor, rs->nor);
        chmin(mn_id, rs->mn_id);
      }
    }
  };
  np pl{}, rt{};

  kdt(it b, it e) {
    int n = e - b;
    pl = new node[n];
    FOR(i, n) {
      var [x, y, id] = b[i];
      pl[i] = node {x, y, x, x, y, y, abs(x) + abs(y), id, id, 0, 0};
    }
    rt = build(pl, pl + n);
  }
  ~kdt() { delete[] pl; }

  np build(np l, np r) {
    if (l == r) return 0;
    int lx = l->x, rx = lx, ly = l->y, ry = ly;
    for (np p = l + 1; p != r; ++p) {
      chmin(lx, p->x), chmax(rx, p->x);
      chmin(ly, p->y), chmax(ry, p->y);
    }
    np m = l + (r - l) / 2;
    if (rx - lx > ry - ly) {
      nth_element(l, m, r, [](var a, var b) { return a.x < b.x; });
    } else {
      nth_element(l, m, r, [](var a, var b) { return a.y < b.y; });
    }
    m->ls = build(l, m), m->rs = build(m + 1, r);
    return m->upd(), m;
  }

  ll dis_box(np p, int x, int y) const {
    ll dx = 0, dy = 0;
    if (x < p->l) dx = p->l - x;
    if (x > p->r) dx = x - p->r;
    if (y < p->c) dy = p->c - y;
    if (y > p->d) dy = y - p->d;
    return dx + dy;
  }

  using nk = pair<ll, int>;
  nk lower(np p, int x, int y) const { return {dis_box(p, x, y), p->mn_id}; }

  void _ne(np p, int x, int y, nk &s, int ban) const {
    if (p->id < ban) {
      ll dx = ll(p->x) - x, dy = ll(p->y) - y;
      chmin(s, nk{abs(dx) + abs(dy), p->id});
    }
    np a = p->ls, b = p->rs;
    if (not a and not b) return;

    nk aa = not a ? nk{inf<ll>, -1} : lower(a, x, y);
    nk bb = not b ? nk{inf<ll>, -1} : lower(b, x, y);

    if (bb < aa) swap(a, b), swap(aa, bb);
    if (a and aa < s) _ne(a, x, y, s, ban);
    if (b and bb < s) _ne(b, x, y, s, ban);
  }

  nk nearest(int x, int y, int ban = -1) const {
    nk s = {inf<ll>, -1};
    _ne(rt, x, y, s, ban);
    return s;
  }

  using fk = pair<ll, int>;
  fk upper(np p, int x, int y) const {
    ll dx = max(abs(x - p->l), abs(x - p->r));
    ll dy = max(abs(y - p->c), abs(y - p->d));
    return {dx + dy, -p->mn_id};
  }

  void _fa(np p, int x, int y, fk &s, int ban) const {
    if (p->id < ban) {
      ll d = abs(p->x - x) + abs(p->y - y);
      chmax(s, fk{d, -p->id});
    }
    np a = p->ls, b = p->rs;
    if (not a and not b) return;
    fk da = not a ? fk{-1, 0} : upper(a, x, y);
    fk db = not b ? fk{-1, 0} : upper(b, x, y);
    if (da < db) swap(a, b), swap(da, db);
    if (a and s < da) _fa(a, x, y, s, ban);
    if (b and s < db) _fa(b, x, y, s, ban);
  }

  nk farest(int x, int y, int ban = -1) const {
    fk s = {-1, 0};
    _fa(rt, x, y, s, ban);
    return {s.fi, -s.se};
  }
};

void Yorisou() {
  INT(N);
  vc<T3<int>> dat(N);
  FOR(i, N) {
    Z &[x, y, id] = dat[i];
    IN(x, y);
    id = i;
  }
  INT(Q);
  VEC(T3<int>, q, Q);
  FOR(i, Q) {
    var [op, x, y] = q[i];
    if (op == 0) dat.ep(x, y, i + N);
  }
  kdt ds(all(dat));
  FOR(i, Q) {
    var [op, x, y] = q[i];
    if (op == 1) {
      print(ds.nearest(x, y, i + N).fi);
    } else if (op == 2) {
      print(ds.farest(x, y, i + N).fi);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}