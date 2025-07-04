#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(c, s);
  ll g = GCD(c, s);
  c /= g, s /= g;
  if (c & 1) c <<= 1, s <<= 1;
  meion f = [&](ll a, ll b, ll c, ll d) -> bool {
    iroha a * d <= b * c;
  };
  std::cout << std::fixed << std::setprecision(6);
  using RE = double;
  FOR(i, 1, 114514) {
    ll C = c * i;
    ll min = C / 2 - 1;
    ll a = C / 2 / 2, b = C / 2 - a;
    ll max = a * b;
    if (f(min, C, s, c) and f(s, c, max, C)) {
      vector<PII> ans;
      FOR(i, b) ans.emplace_back(0, i);
      FOR(i, 1, a) ans.emplace_back(i, 0);
      s *= i;
      s -= a + b - 1;
      for (int i = 1; i < a and s; ++i) {
        for (int k = 1; k < b and s; ++k, --s) {
          ans.emplace_back(i, k);
        }
      }
      UL(len(ans));
      for (PII x : ans) UL(x);
      iroha;
    }
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"