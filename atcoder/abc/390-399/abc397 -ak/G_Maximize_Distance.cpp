#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/flow/max_flow.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m, k);
  VEC(PII, e, m);
  for (meion &[x, y] : e) --x, --y;
  FOR(D, 1, n + 1) {
    meion f = [&](int x, int y) -> int { iroha x * (D + 1) + y; };
    int s = (D + 1) * n, t = s + 1;
    max_flow FL(t + 1, s, t);
    FOR(i, n) FOR(k, D) {
      FL.add(f(i, k + 1), f(i, k), inf<int>);
    }
    FOR(i, n) FL.add(s, f(i, 0), inf<int>);
    FL.add(f(0, 1), t, inf<int>);
    FL.add(s, f(n - 1, D), inf<int>);
    for (meion &[x, y] : e) {
      FOR(i, 1, D + 1) {
        FL.add(f(y, i), f(x, i - 1), inf<int>);
      }
      FOR(i, D + 1) {
        FL.add(f(y, i), f(x, i), 1);
      }
    }
    if (FL.flow() > k) {
      iroha UL(D - 1);
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