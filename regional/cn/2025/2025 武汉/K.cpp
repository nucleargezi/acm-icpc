#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  Z e = a;
  e.insert(e.end(), all(b));
  sort(e);
  FOR(i, N) if (e[i << 1] != e[i << 1 | 1]) return print(-1);
  vector<set<int>> sa(N), sb(N);
  FOR(i, N) sa[--a[i]].eb(i);
  FOR(i, N) sb[--b[i]].eb(i);
  ll c = 0;
  vector<PII> r;
  FOR(i, N) if (a[i] != b[i]) {
    int x = a[i], y = b[i];
    int tx = N, ttx = N, ty = N, tty = N;
    Z it = sa[x].upper_bound(i);
    if (it != sa[x].end()) chmin(tx, *it);
    it = sb[x].upper_bound(i);
    if (it != sb[x].end()) chmin(ttx, *it);
    it = sb[y].upper_bound(i);
    if (it != sb[y].end()) chmin(ty, *it);
    it = sa[y].upper_bound(i);
    if (it != sa[y].end()) chmin(tty, *it);

    if (min(tx, ttx) < min(ty, tty)) {
      if (ttx < tx) {
        swap(tx, ttx);
        int p = a[tx];
        sa[p].extract(tx);
        sb[x].extract(tx);
        sb[p].eb(tx);
        sa[x].eb(tx);
        swap(a[tx], b[tx]);
        r.ep(tx, tx);
      }
      c += tx - i;
      sa[x].extract(tx);
      sb[y].extract(i);
      sb[x].eb(i);
      sa[y].eb(tx);
      swap(a[tx], b[i]);
      r.ep(tx, i);
    } else {
      if (ty > tty) {
        swap(ty, tty);
        int p = b[ty];
        sb[p].extract(ty);
        sa[y].extract(ty);
        sa[p].eb(ty);
        sb[y].eb(ty);
        swap(a[ty], b[ty]);
        r.ep(ty, ty);
      }
      c += ty - i;
      sb[y].extract(ty);
      sa[x].extract(i);
      sa[y].eb(i);
      sb[x].eb(ty);
      swap(a[i], b[ty]);
      r.ep(i, ty);
    }
  }
  print(c, len(r));
  for (Z [l, r] : r) print(++l, ++r);
}
#include "YRS/Z_H/main.hpp"