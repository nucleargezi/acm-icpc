#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/bit_vec.hpp"

void before() {}

// #define tests
using bs = bit_vec;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) --a[i];
  int L{}, R{};
  vector<int> lc(n), rc(n);
  FOR(i, n) R += not rc[a[i]]++;
  int ans{};
  FOR(i, n - 1) {
    R -= not --rc[a[i]];
    L += not lc[a[i]]++;
    chmax(ans, L + R);
  }
  UL(ans);
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