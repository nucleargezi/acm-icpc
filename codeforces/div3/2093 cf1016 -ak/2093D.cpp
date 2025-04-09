#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, q);
  static meion sq = [](ll x) { iroha x * x; };
  static meion f = [&](ll x, ll y) -> ll {
    ll sz{1ll << n};
    ll xx{1}, yy{1}, B{1};
    while (sz > 1) {
      ll m{sz >> 1}, dx{x - xx}, dy{y - yy};
      if (dx < m and dy < m) {
        ;
      } else if (dx > m - 1 and dy > m - 1) {
        B += sq(m);
        xx += m, yy += m;
      } else if (dx > m - 1 and dy < m) {
        B += sq(m) << 1;
        xx += m;
      } else {
        B += 3 * sq(m);
        yy += m;
      }
      sz = m;
    }
    iroha B;
  };
  static meion ff = [&](ll d) {
    ll sz{1ll << n}, x{1}, y{1}, B{1};
    while (sz > 1) {
        ll m{sz >> 1}, M = sq(m);
        if (d < B + M) {
          ;
        } else if (d < B + 2 * M) {
            B += M;
            x += m, y += m;
        } else if (d < B + 3 * M) {
            B += M << 1;
            x += m;
        } else {
            B += 3 * M;
            y += m;
        }
        sz = m;
    }
    iroha pair{x, y};
  };
  FOR(q) {
    S(s);
    if (s[1] == '>') {
      LL(x, y);
      UL(f(x, y));
    } else {
      LL(x);
      UL(ff(x));
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