#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/fenw/fenw01.hpp"

#define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  fenw01 seg(n);
  ll ans = 0;
  FOR(i, n) {
    if (s[i] == 1 or s[i] == -1) seg.add(i);
    else ans += seg.prod_all();
  }
  ll sm = ans;
  FOR_R(i, n) if (s[i] == -1) {
    sm -= n - i - seg.prod(i, n);
    seg.remove(i);
    sm += seg.prod(0, i);
    chmax(ans, sm);
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"