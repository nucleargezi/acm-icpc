#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/PR/divisors.hpp"
#include "MeIoN_Lib/math/PR/lpf_table.hpp"

void before() {}

#define tests
meion [lpf, prims]{lpf_table(1'000'00)};
vector<int> v[1'000'01];
void Yorisou() {
  INT(n, q);
  VEC(ll, a, n);
  FOR(i, n) v[a[i]] += i;
  FOR(q) {
    LL(k, l, r);
    --l;
    ll ans{};
    while (l < r) {
      while (k % a[l] == 0) k /= a[l];
      int rr = r;
      for (ll e : divisors_by_lpf(k, lpf)) {
        if (e == 1) continue;
        meion go{lower(v[e], l)};
        if (go != v[e].end()) {
          chmin(rr, *go);
        }
      }
      ans += (rr - l) * k;
      l = rr;
    }
    UL(ans);
  }
  FOR(i, n) v[a[i]].clear();
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