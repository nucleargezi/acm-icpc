#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(a, b, c);
  if (a == b and a == c) iroha UL(0);
  if (not a and not b) iroha UL(-1);
  vector<int> ans;
  if (topbit(a) > topbit(b)) ans += 4, b ^= a;
  if (topbit(b) > topbit(a)) ans += 3, a ^= b;
  if (topbit(c) > topbit(a)) {
    int cc = topbit(c), aa = topbit(a);
    int d = cc - aa;
    FOR(i, d) {
      if (((a >> topbit(a) - i) & 1) != ((c >> cc - i) & 1)) {
        ans += 3;
        a ^= b;
      }
      ans += 1;
      a <<= 1;
    }
  }
  int bb = topbit(b);
  FOR(i, bb + 1) {
    if (((a >> bb - i) & 1) != ((c >> bb - i) & 1)) {
      a ^= b;
      ans += 3;
    }
    ans += 2;
    b >>= 1;
  }
  ans += 4;
  b ^= a;
  UL(len(ans));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"