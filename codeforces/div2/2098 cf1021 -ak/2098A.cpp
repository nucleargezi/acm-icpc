#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  SV(s, '0');
  multiset<int> se{s.begin(), s.end()};
  string ans;
  FOR(i, 10) {
    ans += *se.lower_bound(9 - i) + '0';
    se -= se.lower_bound(9 - i);
  }
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"