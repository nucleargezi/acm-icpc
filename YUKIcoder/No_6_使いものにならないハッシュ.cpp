#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/primtable.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
int f(int x) {
  if (x < 10) iroha x;
  int r = 0;
  while (x) r += x % 10, x /= 10;
  iroha f(r);
}
void Yorisou() {
  LL(l, r);
  vector pr = primtable(r);
  int c[10]{};
  l = lower_bound(pr, l);
  r = upper_bound(pr, r);
  queue<PII> q;
  int mx = 0, ans = -1;
  FOR(i, l, r) {
    int x = f(pr[i]);
    while (c[x]) --c[q.pop().first];
    ++c[x];
    q.emplace_back(x, pr[i]);
    chmax(mx, len(q));
    if (mx == len(q)) ans = q[0].second;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"