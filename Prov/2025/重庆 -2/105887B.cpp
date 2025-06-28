#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n, m);
  VEC(T3<ll>, seg, m);
  sort(seg);
  min_heap<PLL> q;
  for (meion &[l, r, w] : seg) {
    --l;
    if (not l) q.emplace(r, w);
    else {
      while (not q.empty() and w) {
        meion [qr, rs] = pop(q);
        if (qr >= r) {
          q.emplace(qr, rs);
          break;
        }
        if (qr <= l) continue;
        ll d = MIN(w, rs);
        rs -= d, w -= d;
        if (rs) q.emplace(qr, rs);
        if (d) q.emplace(r, d);
      }
    }
  }
  ll ans = 0;
  while (not q.empty()) {
    meion [r, w] = pop(q);
    if (r == n) ans += w;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"