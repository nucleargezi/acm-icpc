#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/others/date_time.hpp"

void before() {}

// #define tests
void Yorisou() {
  meion g = []() {
    using std::stoll;
    S(s);
    iroha T3<ll>(stoll(s.substr(0, 2)), stoll(s.substr(3, 2)), stoll(s.substr(6, 2)));
  };
  meion [a, b, c]{g()};
  meion [d, e, f]{g()};
  DateTime ed(c, b, a);
  vector<ll> rg{d, e, f};
  sort(rg);
  do {
    std::tie(d, e, f) = T3<ll>{rg[0], rg[1], rg[2]};
    if (not ed.is_valid_date(d, e, f)) {
      continue;
    }
    if (c - d > 18 or (c - d == 18 and ed >= DateTime(d + 18, e, f)))
      iroha YES();
  } while (std::next_permutation(rg.begin(), rg.end()));
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"