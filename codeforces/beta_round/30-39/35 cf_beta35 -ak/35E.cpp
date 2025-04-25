#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/file_io.hpp"

void before() {
#ifdef ONLINE_JUDGE
  FR("input.txt");
  FW("output.txt");
#endif
}

// #define tests
void Yorisou() {
  LL(n);
  vector<T3<ll>> a;
  FOR(n) {
    LL(h, l, r);
    a += T3{l, 1ll, h};
    a += T3{r, -1ll, h};
  }
  sort(a);
  multiset<ll> se{0};
  vector<PLL> ans;
  for (ll l{}, r{}; l < (n << 1); l = r) {
    while (r < (n << 1) and std::get<0>(a[l]) == std::get<0>(a[r])) {
      if (~std::get<1>(a[r])) se += std::get<2>(a[r]);
      else se -= std::get<2>(a[r]);
      ++r;
    }
    ll h = *se.rbegin();
    if (ans.empty()) {
      ans += PLL{std::get<0>(a[l]), 0};
      ans += PLL{std::get<0>(a[l]), h};
    } else {
      if (ans.end()[-1].second == ans.end()[-2].second) {
        ans.end()[-1].first = std::get<0>(a[l]);
      } else {
        ans += PLL{std::get<0>(a[l]), ans.end()[-1].second};
      }
      if (ans.end()[-1].second != h) {
        ans += PLL{std::get<0>(a[l]), h};
      }
    }
  }
  UL(len(ans));
  FOR(i, len(ans)) {
    UL(ans[i]);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"