#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  S(s);
  ll N = n - 1 << 1;
  map<char, ll> m;
  ll ans = 0;
  FOR(i, N) {
    s[i] = std::tolower(s[i]);
    if (i & 1) {
      if (m[s[i]])
        --m[s[i]];
      else
        ++ans;
    } else {
      ++m[s[i]];
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"