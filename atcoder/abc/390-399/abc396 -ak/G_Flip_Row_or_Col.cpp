#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/set/bit_convolution.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  vector<ll> a(1 << m);
  FOR(i, n) {
    S(s);
    int x{};
    FOR(k, m) {
      x |= s[k] - '0' << k;
    }
    ++a[x];
  }
  vector<ll> b(1 << m);
  FOR(i, 1 << m) {
    b[i] = MIN<ll>(popcount(i), m - popcount(i));
  }
  UL(qmin(xor_convolution(a, b)));
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