#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/Wavelet_Matrix.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(ll, a, n);
  Wavelet_Matrix g(a);
  ll ans{};
  vector<vector<int>> v(m);
  FOR(i, n) v[a[i]] += i;
  FOR(i, n) ans += g.count(i + 1, n, 0, a[i]);
  UL(ans);
  FOR(i, 1, m) {
    for (int t{}; int x : v[m - i]) {
      ans += x + x - t - t++ - n + len(v[m - i]);
    }
    UL(ans);
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