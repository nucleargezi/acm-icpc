#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/random/rng.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
  INT(n, m);
  vector<int> a(n);
  FOR(i, n) a[i] = rng();

  ll s{}, ss{SUM(a)};
  vector<ll> to(n);
  FOR(m) {
    INT(f, t);
    --f, --t;
    s += a[f];
    to[t] += a[f];
  }
  vector c(to);

  INT(q);
  FOR(q) {
    INT(op);
    if (op == 1) {
      INT(f, t);
      --f, --t;
      to[t] -= a[f];
      s -= a[f];
    } else if (op == 2) {
      INT(f), --f;
      s -= to[f];
      to[f] = 0;
    } else if (op == 3) {
      INT(f, t);
      --f, --t;
      to[t] += a[f];
      s += a[f];
    } else {
      INT(f), --f;
      s += c[f] - to[f];
      to[f] = c[f];
    }
    YES(s == ss);
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
  MeIoN_is_UMP45();
  iroha 0;
}