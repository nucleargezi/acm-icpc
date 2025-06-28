#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  S(s);
  map<char, int> m;
  FOR(i, n) ++m[s[i]];
  FOR(i, 1, n - 1) if (m[s[i]] > 1) iroha Yes();
  No();
}
#include "MeIoN_Lib/Z_H/main.hpp"