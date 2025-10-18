#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  vector<tuple<int, int, int>> a(N);
  for (Z &[p, l, r] : a) {
    IN(l, r);
    if (l != -1) p = l;
    else if (r != -1) p = r;
    else p = M + 1;
  }
  sort(a);

  set<int> se{0, M + 1};
  for (Z [p, l, r] : a) {
    if (l != -1) se.eb(l);
    if (r != -1) se.eb(r);
  }

  int c = 0;
  while (not a.empty()) {
    Z [p, l, r] = a.back();
    if (p == M + 1) {
      ++c;
      pop(a);
    } else {
      break;
    }
  }

  int s = 0;
  for (Z &[p, l, r] : a) {
    if (l != -1 and r != -1) continue;
    if (l != -1) {
      int p = *se.upper_bound(l);
      r = p - 1;
      se.eb(r);
      s += r - l;
    } else {
      int p = *prev(se.lower_bound(r));
      l = p + 1;
      se.eb(l);
      s += r - l;
    }
    p = l;
  }

  if (not se.contains(1)) {
    se.eb(1);
    int r = *se.upper_bound(1) - 1;
    se.eb(r);
    a.ep(1, 1, r);
    s += r - 1;
    --c;
  }
  if (not se.contains(M)) {
    se.eb(M);
    int l = *prev(se.lower_bound(M)) + 1;
    se.eb(l);
    a.ep(l, l, M);
    s += M - l;
    --c;
  }
  sort(a);

  N = len(a);
  FOR(i, N - 1) {
    Z [p, l, r] = a[i];
    Z [pp, ll, rr] = a[i + 1];
    if (ll - r != 1) {
      --c;
      s += ll - r - 2;
      a.ep(r + 1, r + 1, ll - 1);
    }
  }
  sort(a);
  N = len(a);
  FOR(i, N - 1) {
    Z [p, l, r] = a[i];
    Z [pp, ll, rr] = a[i + 1];
    if (l > r or ll > rr or r >= ll) return NIE();
  }
  if (c < 0 or c > s) return NIE();
  TAK();
}
#include "YRS/Z_H/main.hpp"