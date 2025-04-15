#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/factors.hpp"

vector<ll> v;
void before() {
  FOR(i, 2, 1'000'001) {
    if (len(factor(i)) == 2) v += i * i;
  }
}

#define tests
void Yorisou() {
  LL(A);
  UL(v[upper_bound(v, A) - 1]);
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