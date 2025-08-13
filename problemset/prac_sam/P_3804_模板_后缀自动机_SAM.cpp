#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/SAM.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  const int n = len(s);
  SAM sam(n);
  vector sz = sam.get_sz(s, 'a');
  ll ans = 0;
  FOR(i, len(sam)) {
    if (sz[i] > 1) chmax(ans, 1ll * sz[i] * sam[i].len);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"