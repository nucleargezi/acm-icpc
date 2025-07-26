#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/seg/lichao_tree.hpp"

// #define tests
using line = Line<ll>;
void Yorisou() {
  LL(n, q);
  vector<ll> pos;
  vector<tuple<ll, ll, ll, ll, ll>> quis;
  FOR(n) {
    LL(l, r, a, b);
    quis.emplace_back(0, l, r, a, b);
  }
  FOR(q) {
    LL(op);
    if (op == 0) {
      LL(l, r, a, b);
      quis.emplace_back(0, l, r, a, b);
    } else {
      LL(x);
      quis.emplace_back(1, x, x, x, x);
      pos.emplace_back(x);
    }
  }
  lichao_tree<line, 1, 1> seg(pos, {0, inf<ll>});
  for (meion [op, l, r, a, b] : quis) {
    if (op == 0) {
      seg.chmin_segment(l, r, {a, b});
    } else {
      ll ans = seg.quis(l).first;
      print("{}", ans == inf<ll> ? "NO" : to_str(ans));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"