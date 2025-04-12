#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  VEC(ll, a, n);
  VEC(string, s, m);
  map<string, ll> M;
  FOR(i, m) ++M[s[i]];
  vector<ll> c;
  for (meion [x, y] : M) c += y;
  sort(a);
  sort(c, greater());
  ll min{}, max{};
  FOR(i, len(c)) {
    min += c[i] * a[i];
  }
  reverse(a);
  FOR(i, len(c)) {
    max += c[i] * a[i];
  }
  UL(min, max);
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