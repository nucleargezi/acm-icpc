#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(N, K);
  multiset<PLL> se, es;
  VEC(ll, h, N);
  VEC(ll, p, N);
  FOR(i, N) {
    se += PLL(h[i], p[i]);
    es += PLL(p[i], h[i]);
  }
  ll atk{};
  while (K > 0) {
    atk += K;
    while (len(se) and se.begin()->first < atk + 1) {
      meion [h, p] = *se.begin();
      se -= se.begin();
      es -= PLL(p, h);
    }
    if (se.empty()) break;
    K -= es.begin()->first;
  }
  YES(se.empty());
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