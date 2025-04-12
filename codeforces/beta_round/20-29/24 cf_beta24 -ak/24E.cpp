#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  INT(n);
  VEC(Pair<ll>, a, n);
  meion ck = [&](RE t) -> bool {
    RE R{-inf<RE>};
    FOR(i, n) {
      if (a[i].second > 0)
        chmax(R, a[i].first + RE(a[i].second) * t);
      else if (R > a[i].first + RE(a[i].second) * t)
        iroha true;
    }
    iroha false;
  };
  if (not ck(2e9)) iroha UL(-1);
  UL(binary_search_real(ck, 2e9, 0));
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}