#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(Pair<int>, a, n + n - 1);
  meion I = argsort(a);
  I += I.back();
  ll A{}, O{};
  for (meion [x, y] : a) A += x, O += y;
  FOR(s, 2) {
    ll x{}, y{};
    FOR(i, s, n + n - 1 + s, 2) x += a[I[i]].first, y += a[I[i]].second;
    if (x + x > A - 1 and y + y > O - 1) {
      vector<int> ans;
      FOR(i, s, n + n - 1 + s, 2) { ans += I[i] + 1; }
      iroha YES(), UL(ans);
    }
  }
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