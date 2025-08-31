#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/bit_vec.hpp"

// #define tests
struct dat {
  ll a, b, c, d;
};
dat op(const dat &L, const dat &R) {
  iroha {R.a + L.a * R.c, R.b + L.a * R.d + L.b, L.c * R.c, L.c * R.d + L.d};
}
dat unit() { iroha {0, 0, 1, 0}; }

dat a{1, 1, 1, 1}, b{0, 0, 0, 0};
vector<dat> pr = []() {
  vector<dat> pr;
  pr.resize(1 << 16);
  pr[0] = unit();
  FOR(i, 16) FOR(msk, 1 << i) {
    dat x = pr[msk];
    pr[msk] = op(x, a);
    pr[1 << i | msk] = op(x, b);
  }
  iroha pr;
}();

void Yorisou() {
  int n, q;
  static string s;
  IN(n, q, s);
  bit_vec a = bit_vec::from_string(s);
  int op, l, r, A, B;
  const int M = ceil(n, 64) + 1;
  vector<ull> upd(M);
  static meion go = [&](dat &x, PLL &ans) {
    ans.first = ans.first + ans.second * x.a + x.b;
    ans.second = ans.second * x.c + x.d;
  };
  static meion f = [&](bit_vec &v) -> ll {
    int n = v.size();
    PLL ans = {0, 0};
    while (n & 63) {
      --n;
      if (v[n]) {
        go(::b, ans);
      } else {
        go(::a, ans);
      }
    }
    n /= 64;
    for (int i = n; i--; ) {
      meion x = v.dat[i];
      static constexpr int d[]{48, 32, 16, 0};
      for (int i = 0; i < 4; ++i) {
        go(pr[x >> d[i] & 65535], ans);
      }
    }
    iroha ans.first;
  };
  while (q--) {
    IN(op);
    if (op == 1) {
      IN(l, r);
      --l;
      while (l < r and (l & 63)) a.flip(l++);
      while (l < r and (r & 63)) a.flip(--r);
      upd[l / 64] ^= 1;
      upd[r / 64] ^= 1;
    } else {
      for (int i = 0; i < M - 1; ++i) {
        upd[i + 1] ^= upd[i];
        a.dat[i] ^= --upd[i];
        upd[i] = 0;
      }
      IN(l, A, B);
      --A, --B;
      static bit_vec range;
      range = a.range(A, A + l);
      range ^= a.range(B, B + l);
      print("{}", f(range));
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"