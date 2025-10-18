#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/set/bit_convolution.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
void Yorisou() {
  INT(n);
  VEC(mint, a, 1 << n);
  VEC(mint, b, 1 << n);
  UL(or_convolution(a, b));
  UL(and_convolution(a, b));
  UL(xor_convolution(a, b));
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