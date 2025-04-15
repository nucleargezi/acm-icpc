#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
using H = HASH<string>;
void Yorisou() {
  S(s);
  const int n{len(s)};
  meion [L, R] = get_hash_LR<H>(s);
  FOR_R(i, 1, n + 1) {
    if (palindrome(L, R, n - i, n)) {
      string bac = s.substr(0, n - i);
      reverse(bac);
      iroha UL(s + bac);
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