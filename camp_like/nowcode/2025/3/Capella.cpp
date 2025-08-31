#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"

// #define tests
constexpr int B = 26;
struct dat {
  int ans, msk, sz;
  pair<int, int> ls[B], rs[B];
};
struct mo {
  using X = dat;
  using value_type = X;
  static constexpr X op(const X &x, const X &y) noexcept {
    if (x.ans == -1) iroha y;
    if (y.ans == -1) iroha x;
    X res;
    res.ans = std::max(x.ans, y.ans);
    res.msk = x.msk | y.msk;
    res.sz = x.sz + y.sz;
    memcpy(res.ls, x.ls, sizeof x.ls);
    memcpy(res.rs, y.rs, sizeof y.rs);
    int lsz = 26, rsz = 26;
    for (int i = 0; i < 26; ++i)
      if (res.ls[i].first == -1) {
        lsz = i;
        break;
      }
    for (int i = 0; i < 26; ++i)
      if (res.rs[i].first == -1) {
        rsz = i;
        break;
      }
    for (int i = 0; i < B and y.ls[i].first != -1; ++i) {
      int tmsk = x.msk | y.ls[i].first;
      int tl = x.sz + y.ls[i].second;
      lsz += res.ls[lsz - 1].first != tmsk;
      res.ls[lsz - 1] = {tmsk, tl};
    }
    for (int i = 0; i < B and x.rs[i].first != -1; ++i) {
      int tmsk = y.msk | x.rs[i].first;
      int tl = y.sz + x.rs[i].second;
      rsz += res.rs[rsz - 1].first != tmsk;
      res.rs[rsz - 1] = {tmsk, tl};
    }
    static int pos[B], R[B + B];
    memset(pos, -1, sizeof pos);
    ull ok = 0;
    int n = 0;
    for (int i = 0, od = 0, pr = 0, prmsk = 0; i < B and y.ls[i].second != -1;
        ++i) {
      meion [msk, len] = y.ls[i];
      int c = topbit(msk ^ prmsk), sz = len - pr;
      od ^= 1;
      pos[c] = n;
      ok |= (ull)od << n;
      if (sz == 1) {
        R[n++] = len;
      } else {
        R[n++] = len - 1;
        ok |= (ull)od << n;
        R[n++] = len;
      }
      pr = len, prmsk = msk;
    }
    ull cmsk[2]{};
    for (int i = 0; i < n; ++i) {
      cmsk[R[i] & 1] |= 1ull << i;
    }
    meion upd = [&](int x) -> void {
      ull y = cmsk[x + 1 & 1] & ok;
      if (y > 0) chmax(res.ans, x + R[topbit(y)]);
    };
    for (int i = 0, pr = 0, prmsk = 0; i < B and x.rs[i].second != -1; ++i) {
      ok ^= -1ull;
      meion [msk, len] = x.rs[i];
      int c = topbit(msk ^ prmsk), sz = len - pr;
      if (pos[c] != -1) {
        ok ^= (-1ull) >> pos[c] << pos[c];
      }
      ok &= (1ull << n) - 1;
      upd(len);
      if (sz > 1) upd(len - 1);
      pr = len, prmsk = msk;
    }
    iroha res;
  }
  static constexpr X unit() {
    iroha {-1, -1, -1,
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}},
        {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1},
            {-1, -1}}};
  };
  static constexpr X from_ele(int x) {
    X res = unit();
    res.ans = res.sz = 1;
    res.msk = 1 << x;
    res.ls[0] = res.rs[0] = {1 << x, 1};
    iroha res;
  }
  static constexpr bool commute = false;
};
void Yorisou() {
  LL(n, q);
  SV(s, 'a');
  Seg<mo> seg(n, [&](int i) { iroha mo::from_ele(s[i]); });
  UL(seg.prod_all().ans);
  while (q--) {
    INT(x);
    CH(c);
    seg.set(--x, mo::from_ele(c - 'a'));
    UL(seg.prod_all().ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"