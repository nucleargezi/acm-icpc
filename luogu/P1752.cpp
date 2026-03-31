#include "YRS/all.hpp"

void Yorisou() {
  INT(N, M, p, q);
  VEC(PII, g, M);
  VEC(int, a, p);
  VEC(int, b, q);
  sort(g);
  sort(a, greater());
  sort(b, greater());
  N -= p + q;
  Z ck = [&](ll t) -> bool {
    max_heap<int> q;
    int i = M - 1;
    for (ll x : a) {
      while (i >= 0 and g[i].fi >= x) q.eb(g[i].se), --i;
      int ti = t;
      while (si(q) and ti) --ti, pop(q);
    }
    while (i >= 0) q.eb(g[i].se), --i;
    int ls = 0;
    for (ll x : b) {
      while (si(q) and q.top() > x) ++ls, pop(q);
      int ti = t;
      while (si(q) and ti) --ti, pop(q);
    }
    ls += si(q);
    return ls <= N * t;
  };
  if (not ck(M)) return print(-1);
  print(bina(ck, M, 0));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"