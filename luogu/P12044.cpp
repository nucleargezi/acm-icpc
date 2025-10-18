#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/basic/bit_vec.hpp"

void before() {}

// #define tests
using bs = bit_vec;
void Yorisou() {
  LL(n);
  ll m = 3 * n - 3;
  vector a(n, bit_vec(m));
  FOR(i, n) {
    S(s);
    FOR(k, m) {
      if (s[k] == '1') a[i][k] = 1;
    }
  }
  vector<bs> basis;
  vector<bs> go;
  meion add = [&](int i) -> void {
    meion &x = a[i];
    bs y(n);
    y[i] = 1;
    FOR(i, len(basis)) {
      if (chmin(x, x ^ basis[i])) {                                                                   
        y ^= go[i];
      }
    }
    if (not x.any()) iroha;
    FOR(i, len(basis)) {
      if (chmin(basis[i], x ^ basis[i])) {
        go[i] ^= y;
      }
    }
    basis.emplace_back(x);
    go.emplace_back(y);
  };
  FOR(i, n) add(i);
  bs tmp(m), y(n);
  vector<int> ans;
  FOR(i, len(basis)) {
    tmp.reset();
    y.reset();
    FOR(k, i, len(basis)) {
      tmp ^= basis[k];
      y ^= go[k];
      ll c = tmp.count();
      if (m - n + 2 > c and c > n - 1) {
        FOR(i, n) if (y[i]) ans += i + 1;
        iroha UL(len(ans)), UL(ans);
      }
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"