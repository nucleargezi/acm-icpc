#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  S(s);
  const int n = len(s);
  vector<int> a(n);
  FOR(i, n) {
    a[i] = s[i] == '(' ? 1 : -1;
  }
  a = pre_sum<false>(a);
  FOR(i, n - 1) if (not a[i]) iroha YES();
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"