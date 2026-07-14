#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

struct kdt_man {
  using it = vc<T3<ll>>::iterator;
  struct node;
  using np = node *;
  struct node {
    ll x, y, l, r, c, d;
    ll nor;
    ll id, mn_id;
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

  kdt_man(it b, it e) {
    ll n = e - b;
    pl = new node[n];
    FOR(i, n) {
      var [x, y, id] = b[i];
      pl[i] = node {x, y, x, x, y, y, abs(x) + abs(y), id, id, 0, 0};
    }
    rt = build(pl, pl + n);
  }
  ~kdt_man() { delete[] pl; }

  np build(np l, np r) {
    if (l == r) return 0;
    ll lx = l->x, rx = lx, ly = l->y, ry = ly;
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

  max_heap<ll> q;
  ll lower(np s, ll x, ll y) const {
    ll dx = max({0ll, s->l - x, x - s->r});
    ll dy = max({0ll, s->c - y, y - s->d});
    return dx + dy;
  }
  void add(ll d, ll k) {
    if (si(q) < k) q.eb(d);
    else if (d < q.top()) q.pop(), q.eb(d);
  }

  void _kth(np s, ll x, ll y, ll k, ll ban) {
    if (s->id != ban) add(abs(s->x - x) + abs(s->y - y), k);
    np a = s->ls, b = s->rs;
    if (not a and not b) return;
    ll da = a ? lower(a, x, y) : inf<ll>, db = b ? lower(b, x, y) : inf<ll>;
    if (da > db) swap(a, b), swap(da, db);
    if (a and (si(q) < k or da < q.top())) _kth(a, x, y, k, ban);
    if (b and (si(q) < k or db < q.top())) _kth(b, x, y, k, ban);
  }

  void kth_ne(ll x, ll y, ll k, ll ban) { _kth(rt, x, y, k, ban); }
};

void Yorisou() {
  INT(N, K);
  vc<T3<ll>> a(N);
  FOR(i, N) {
    Z &[x, y, id] = a[i];
    IN(x, y);
    id = i;
  }
  kdt_man ds(all(a));
  for (var [x, y, i] : a) ds.kth_ne(x, y, K + K, i);
  vc<ll> s;
  while (si(ds.q)) s.ep(pop(ds.q));
  reverse(s);
  FOR(i, K) print(s[i << 1]);
}

int main() {
  Yorisou();
  return 0;
}