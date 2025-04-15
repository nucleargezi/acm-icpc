#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(ll, a, n);
  map<ll, ll> M;
  vector I = argsort(a);
  vector<ll> ans(n);
  for (ll s{}; ll x : std::views::reverse(I)) {
    ans[x] = ++s - M[a[x]]++;
  }
  FOR(i, n) UL(ans[i]);
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