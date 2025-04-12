#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  HASH H(a);
  int s{};
  FOR(i, 1, n + 1) {
    int l{s + i - 1}, r{s + i + i - 1};
    if (r > n - 1) break;
    while (r < n) {
      int x{get_lcs(H, l + 1 - i, l + 1, H, r + 1 - i, r + 1)},
          y{get_lcp(H, l, n, H, r, n)};
      if (x + y > i) chmax(s, r - x + 1);
      l += i, r += i;
    }
  }
  UL(n - s);
  UL(vector<int>{a.begin() + s, a.end()});
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