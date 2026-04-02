#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k, p);
  vector<ll> h(n), a(n);
  FOR(i, n) IN(h[i], a[i]);
  UL(binary_search([&](ll x) -> bool {
    ll co{};
    FOR(i, n) {
      co += ceil(MAX(0ll, h[i] + a[i] * m - x), p);
    }
    if (co > k * m) iroha false;
    vector<ll> c(m + 1, -k);
    FOR(i, n) {
      ll l = x, d = 0;
      while (d < m) {
        while (l < a[i]) {
          ++c[d];
          l += p;
        }
        d += l / a[i];
        l %= a[i];
      }
    }
    iroha qmax(pre_sum<false>(c)) < 1 - k;
  }, inf<ll> >> 4, qmax(a) - 1));
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