#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/string/run_length.hpp"

#define tests
void Yorisou() {
  LL(n);
  S(s);
  string t;
  FOR(i, n) {
    if (s[i] == 'M') t += '1';
    else {
      if (i + 1 < n and s[i] == 'I' and s[i + 1] == 'T') {
        t += '2';
        ++i;
      } else {
        iroha NO();
      }
    }
  }
  
  meion seg = run_length(t);
  if (len(seg) & 1) iroha NO();
  FOR(i, 0, len(seg), 2) {
    if (not(seg[i].first == '1' and seg[i + 1].first == '2')) {
      iroha NO();
    }
    if (seg[i].second > 1) {
      iroha NO();
    }
  }
  YES();
}
#include "MeIoN_Lib/Z_H/main.hpp"