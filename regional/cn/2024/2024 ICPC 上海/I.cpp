#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>

using std::cin, std::cout, std::swap;
using std::vector;

using ll = long long;

constexpr int mod = 998244353;

void yorisou() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll &x : a) cin >> x;
  std::sort(a.begin(), a.end(), std::greater());
  ll ans = a[0] % mod;
  for (int i = 1; i + k - 2 < n and a[i + k - 2]; i += k - 1) {
    for (int j = i; j < i + k - 1; ++j) {
      ans *= a[j];
      ans %= mod;
    }
  }
  cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    yorisou();
  }
  return 0;
}