#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

// #define tests
using line = Line<ll>;
void Yorisou() {
  LL(n, q);
  vector<T3<ll>> quis;
  FOR(n) {
    LL(x, y);
    quis.emplace_back(0, x, y);
  }
  vector<ll> pos;
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(x, y);
      quis.emplace_back(0, x, y);
    } else {
      LL(x);
      pos.emplace_back(x);
      quis.emplace_back(1, x, x);
    }
  }
  lichao_tree<line, 1, 1> seg(pos, {0, inf<ll>});
  for (meion [op, x, y] : quis) {
    if (op == 0) {
      seg.chmin_line({x, y});
    } else {
      UL(seg.quis(x).first);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"