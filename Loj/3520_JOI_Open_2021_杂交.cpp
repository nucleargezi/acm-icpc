#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/seg/range_assign_seg.hpp"
#include "YRS/al/m/hash.hpp"

using MX = monoid_hash<>;
u8 to[1000];
void Yorisou() {
  to['J'] = 0, to['O'] = 1, to['I'] = 2;
  INT(N);
  vc<int> s[3];
  FOR(k, 3) {
    STR(str);
    sh(s[k], N);
    FOR(i, N) s[k][i] = to[(int)str[i]];
  }

  set<MX::X> se;
  FOR(i, 3) FOR(k, 3) FOR(j, 3) if ((i + k + j) % 3 == 1) {
    vc<MX::X> hs(N);
    FOR(l, N) {
      int x = i * s[0][l] + k * s[1][l] + j * s[2][l];
      x = (x % 3 + 3) % 3;
      hs[l] = MX::sing(x);
    }
    FOR(i, 1, N) hs[i] = MX::op(hs[i - 1], hs[i]);
    se.eb(hs.back());
  }

  INT(Q);
  range_assign_seg<MX> seg(N, [&](int i) {
    CH(c);
    return MX::sing(to[(int)c]);
  });
  Yes(se.contains(seg.prod_all()));
  FOR(Q) {
    INT(l, r);
    CH(c);
    --l;
    seg.assign(l, r, MX::sing(to[(int)c]));
    Yes(se.contains(seg.prod_all()));
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"