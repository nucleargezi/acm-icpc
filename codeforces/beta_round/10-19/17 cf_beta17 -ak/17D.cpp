#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"

void before() {}

// #define tests
using mint = dmint;
void Yorisou() {
  SV(B, '0');
  SV(n, '0');
  INT(mod);
  mint::set_mod(mod);
  [&]() {
    reverse(n);
    meion f = [&](meion &f ,int x) -> void {
      if (n[x]) --n[x];
      else n[x] = 9, f(f, x + 1);
    };
    f(f, 0);
  }();
  mint b;
  for (int c : B) b = b * 10 + c;
  mint ans = b - 1, pow = b;
  for (int x : n) {
    ans *= pow.ksm(x);
    pow = pow.ksm(10);
  }
  UL(ans.val ? ans.val : mod);
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