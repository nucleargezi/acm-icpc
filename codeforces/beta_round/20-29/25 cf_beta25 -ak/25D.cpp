#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n);
  vector<pair<int, int>> L, R;
  dsu f(n);
  FOR(n - 1) {
    INT(x, y);
    if (not f.merge(--x, --y)) {
      L += {x + 1, y + 1};
    }
  }
  meion gs = f.get_group();
  FOR(i, len(gs) - 1) {
    R += {gs[i][0] + 1, gs[i + 1][0] + 1};
  }
  UL(len(L));
  FOR(i, len(L)) UL(L[i], R[i]);
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