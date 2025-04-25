#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  s = ',' + s;
  vector<ll> a;
  for (char c : s) {
    if (c == ',') a += 0;
    else a.back() = a.back() * 10 + c - '0';
  }
  sort(a);
  vector<PLL> res;
  set<ll> se;
  for (ll x : a) {
    if (not se.emplace(x).second) continue;
    if (not res.empty() and res.back().first <= res.back().second and res.back().second + 1 == x) {
      ++res.back().second;
    } else if (not res.empty() and res.back().first >= res.back().second and res.back().second - 1 == x) {
      --res.back().second;
    } else {
      res += PLL(x, x);
    }
  }
  sort(res);
  string ans;
  for (meion [l, r] : res) {
    if (l > r) std::swap(l, r);
    if (l == r) ans += to_str(l) + ',';
    else ans += to_str(l) + '-' + to_str(r) + ',';
  }
  ans.pop_back();
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"