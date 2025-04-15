#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/BM_dense.hpp"

void before() {}

// #define tests
using RE = f128;
void Yorisou() {
  INT(n);
  VEC(PLL, a, n << 1);
  vector<tuple<i128, int, int>> e;
  meion f = [](ll x) -> i128 { iroha i128(x) * x; };
  FOR(i, n) FOR(k, n) {
    e.emplace_back(
        f(a[i].first - a[k + n].first) + f(a[i].second - a[k + n].second), i, k);
  }
  sort(e);
  using bs = bit_vec;
  UL(sqrtf128(std::get<0>(e[binary_search([&](int m) -> bool {
    vector<bs> v(n, bit_vec(n));
    FOR(i, m) {
      meion [d, x, y] = e[i];
      v[x][y] = 1;
    }
    iroha len(B_matching_dense(v, n, n).matching()) == n;
  }, n * n, 0) - 1])));
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