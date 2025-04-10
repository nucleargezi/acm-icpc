#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using RE = long double;
void Yorisou() {
  LL(a, b, c);
  if (not a and not b and not c) iroha UL(-1);
  if (not a and not b) iroha UL(0);
  if (not a) iroha UL(1), UL(RE(-c) / b);
  
  ll D{b * b - 4 * a * c};
  if (D > 0) {
    UL(2);
    vector<RE> ans{(-b - std::sqrt(D)) / 2 / a, (-b + std::sqrt(D)) / 2 / a};
    sort(ans);
    UL(ans[0]);
    UL(ans[1]);
  } else if (D == 0) {
    UL(1);
    UL(-b / 2 / a);
  } else {
    UL(0);
  }
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(10);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}