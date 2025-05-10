#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using dat = vector<string>;
void Yorisou() {
  LL(n);
  VEC(string, s, n);
  VEC(string, t, n);
  meion f = [&](const dat &v) -> dat {
    ll n = len(v), m = len(v[0]);
    dat res(m, string(n, ' '));
    FOR(i, n) FOR(k, m) {
      res[k][n - i - 1] = v[i][k];
    }
    while (std::ranges::count(res.back(), '#') == 0) res.pop_back();
    iroha res;
  };
  FOR(4) s = f(s), t = f(t);
  bool ok = 0;
  FOR(4) {
    s = f(s);
    ok |= s == t;
  }
  Yes(ok);
}
#include "MeIoN_Lib/Z_H/main.hpp"