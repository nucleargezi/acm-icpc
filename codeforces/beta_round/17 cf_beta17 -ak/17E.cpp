#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/string/hash.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

// #define tests
using mint = modint<51123987>;
void Yorisou() {
  INT(n);
  S(s);
  meion ss = s;
  reverse(ss);
  HASH_sin H(s), RH(ss);
  mint ans;
  vector<ll> L(n + 1), R(L);
  FOR(i, n) {
    int r{palindrome_R(H, RH, i, i)};
    ans += r + 1;
    ++L[i - r], --L[i + 1];
    ++R[i], --R[i + r + 1];
  }
  FOR(i, 1, n) {
    int r{palindrome_R(H, RH, i, i - 1)};
    ans += r;
    ++L[i - r], --L[i];
    ++R[i], --R[i + r];
  }
  L = pre_sum<false>(pre_sum<false>(L));
  R = pre_sum<false>(R);
  ans = ans * (ans - 1) / 2;
  FOR(i, n) {
    ans -= R[i] * (L[n] - L[i]);
  }
  UL(ans.val);
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