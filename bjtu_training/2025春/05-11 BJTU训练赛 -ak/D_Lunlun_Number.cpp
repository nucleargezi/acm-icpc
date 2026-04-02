#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  vector<ll> a;
  meion f = [&](meion &f, string s = "") -> void {
    if (s.empty()) {
      FOR(i, '1', '9' + 1) {
        f(f, string{char(i)});
      }
      iroha;
    }
    a += std::stoll(s);
    if (len(s) > 9) iroha;
    FOR(i, MAX<ll>(s.back() - 1, '0'), MIN<ll>(s.back() + 1, '9') + 1) {
      f(f, s + char(i));
    }
  };
  f(f);
  sort(a);
  LL(k);
  UL(a[--k]);
}
#include "MeIoN_Lib/Z_H/main.hpp"