#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, q);
  vector<ll> p(n);
  FOR(i, n) p[i] = i;
  vector f = p, t = p;
  FOR(q) {
    LL(op);
    if (op == 1) {
      LL(a, b);
      f[--a] = t[--b];
    } else if (op == 2) {
      LL(a, b);
      ll x = t[--a], y = t[--b];
      std::swap(p[x], p[y]);
      std::swap(t[a], t[b]);
    } else {
      LL(a);
      UL(p[f[--a]] + 1);
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