#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  VEC(ll, a, 7);
  map<ll, ll> M;
  FOR(i, 7) ++M[a[i]];
  int x{}, y{};
  for (meion &[_, v] : M) x += v > 2, y += v > 1;
  Yes(x and y > 1);
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