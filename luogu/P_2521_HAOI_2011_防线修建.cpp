#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/ds/dynamic_hull.hpp"

// #define tests
using P = point<ll>;
using RE = long double;
void Yorisou() {
  INT(N, x, y);
  dynamic_hull<ll> seg;
  seg.add(P(0, 0));
  seg.add(P(N, 0));
  seg.add(P(x, y));
  INT(M);
  VEC(P, p, M);
  INT(Q);
  vector<PII> quis;
  vector<u8> vis(M, 1);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(i);
      --i;
      vis[i] = 0;
      quis.ep(op, i);
    } else {
      quis.ep(op, op);
    }
  }
  FOR(i, M) if (vis[i]) seg.add(p[i]);
  vector<RE> ans;
  for (Z [op, i] : reversed(quis)) {
    if (op == 1) {
      seg.add(p[i]);
    } else {
      ans.ep(seg.shucho());
    }
  }
  setp(2);
  for (RE x : reversed(ans)) {
    print(x - N);
  }
}
#include "YRS/Z_H/main.hpp"