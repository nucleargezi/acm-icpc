#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <bitset>

using std::cin, std::cout, std::swap;
using std::vector, std::array, std::bitset;

using ll = long long;

ll binary(const auto &f, ll l, ll r) {
  while (std::abs(l - r) > 1) {
    ll x = (r + l) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}
ll E(ll a, ll b, ll x) {
  return a * x + b;
}
void yorisou() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n), x(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) cin >> x[i];
  std::ranges::sort(x);
  ll l = -2'000'000'000'000'000'000, r = 2'000'000'000'000'000'001;
  auto ck = [&](ll m) -> bool {
    int ans = 0;
    vector<int> L, R;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        ans += (b[i] >= m);
      } else if (a[i] > 0) {
        if (E(a[i], b[i], x[n - 1]) < m) continue;
        int p = binary([&](ll idx) -> bool {
          return E(a[i], b[i], x[idx]) >= m;
        }, n - 1, -1);
        R.emplace_back(p);
      } else {
        if (E(a[i], b[i], x[0]) < m) continue;
        int p = binary([&](ll idx) -> bool {
          return E(a[i], b[i], x[idx]) >= m;
        }, 0, n);
        L.emplace_back(p);
      }
    }
    std::ranges::sort(L);
    std::ranges::sort(R, std::greater());
    int l = 0;
    for (int x : L) {
      if (x >= l) ++l;
    }
    int r = 0;
    for (int x : R) {
      if (x <= (n - r - 1)) ++r;
    }
    return ans + l + r >= (n + 1) / 2;
  };
  cout << binary(ck, l, r) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    yorisou();
  }
  return 0;
}