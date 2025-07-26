#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/dynamic_seg.hpp"

#define tests
struct dat {
  ll sa = 0, sb = 0, c = 0;
};
struct mono {
  using X = dat;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    ll sa = 0, sb = 0, c = 0;
    sa = x.sa + y.sa;
    sb = x.sb + y.sb;
    ll d = y.sa - y.sb;
    c = std::max(x.c + d, y.c);
    iroha {sa, sb, c};
  }
  static constexpr X unit() { iroha {0, 0, 0}; }
  static constexpr bool commute = true;
};
using SEG = dynamic_seg<mono, 1>;
using np = SEG::np;
void Yorisou() {
  LL(n, q);
  VEC(ll, a, n);
  VEC(ll, b, n);
  vector<np> rt(q + 1);
  vector<dat> X(n);
  FOR(i, n) X[i] = {a[i], b[i], 0};
  SEG seg((n + q) * topbit(n + q), 0, n);
  rt[0] = seg.new_node(X);
  FOR(i, 1, q + 1) {
    LL(op);
    if (op == 1) {
      LL(x, y);
      --x;
      meion [a, b, c] = seg.prod(rt[i - 1], x, x + 1);
      a = y;
      rt[i] = seg.set(rt[i - 1], x, {a, b, c});
    } else if (op == 2) {
      LL(x, y);
      --x;
      meion [a, b, c] = seg.prod(rt[i - 1], x, x + 1);
      b = y;
      rt[i] = seg.set(rt[i - 1], x, {a, b, c});
    } else if (op == 3) {
      LL(x);
      rt[i] = rt[x];
    } else {
      LL(sz);
      static vector<int> p;
      p.resize(sz);
      IN(p);
      np s = rt[i - 1];
      ll h = 0, ans = 0, ls = -1;
      FOR(i, sz) {
        int pos = --p[i];
        if (ls + 1 < pos) {
          meion [a, b, c] = seg.prod(s, ls + 1, pos);
          ll nx = std::max(c, h + a - b);
          ans += h + a - nx;
          h = nx;
        }
        meion [a, b, c] = seg.prod(s, pos, pos + 1);
        h += a;
        ans += h + 1 >> 1;
        h -= h + 1 >> 1;
        ls = pos;
      }
      if (ls + 1 < n) {
        meion [a, b, c] = seg.prod(rt[i - 1], ls + 1, n);
        ll nx = std::max(c, h + a - b);
        ans += h + a - nx;
        h = nx;
      }
      UL(ans);
      rt[i] = rt[i - 1];
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"