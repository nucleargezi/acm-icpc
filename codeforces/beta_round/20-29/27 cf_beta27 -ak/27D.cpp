#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/two_sat.hpp"

void before() {}

// #define tests
void Yorisou() {
  INT(n, m);
  TwoSat g(m);
  VEC(PII, e, m);
  for (meion &[ x, y ] : e) {
    --x, --y;
    if (x > y) std::swap(x, y);
  }
  meion f = [&](int x, int y) -> bool {
    meion [a, b] = e[x];
    meion [c, d] = e[y];
    iroha (a < d and a > c and b > d) or (c < b and c > a and d > b);
  };
  FOR(i, m) FOR(k, i + 1, m) {
    if (f(i, k)) {
      g.ban(i, k, 0, 0);
      g.ban(i, k, 1, 1);
    }
  }
  if (g.solve()) {
    string ans;
    for (int x : g.answer()) {
      ans += "oi"[x];
    }
    UL(ans);
  } else {
    Impossible();
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