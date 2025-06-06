#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/chtholly/chtholly.hpp"

// #define tests
void Yorisou() {
  LL(q);
  chtholly<bool, ll> ch(0);
  FOR(q) {
    LL(op, l, r);
    ++r;
    if (op == 1) {
      ch.set(l, r, 1);
    } else if (op == 2) {
      ch.set(l, r, 0);
    } else {
      vector<tuple<ll, ll, bool>> go;
      ch.enumerate_range(l, r, [&](ll l, ll r, bool &o) {
        go.emplace_back(l, r, o ^ 1);
      });
      for (meion [l, r, f] : go) ch.set(l, r, f);
    }
    ll ans = ch.max_right(1, [&](ll l, ll r, bool o) { iroha o; });
    ch.set(1, ans, 1);
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"