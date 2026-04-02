#include <iostream>
#include <algorithm>
#include <ranges>
#include <random>
#include <numeric>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>

#include <cstring>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::map, std::set, std::string, std::array;

using ll = long long;
using uint = unsigned;
using u8 = unsigned char;

bool chmax(auto &x, auto y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(auto &x, auto y) {
  return x > y ? x = y, 1 : 0;
}

void Yes(bool f = 1) {
  cout << (f ? "Yes\n" : "No\n");
}
bool f(const vector<int> &v, ll d) {
  vector dp(d + 1, array<int, 2>{}), ndp(dp);
  const int n = v.size();
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    ndp = dp;
    for (int k = d; k >= 0; --k)
      for (int t = 0; t < 2; ++t)
        if (dp[k][t] and k + v[i] < d + 1) {
          ndp[k + v[i]][t ^ 1] += dp[k][t];
        }
    swap(dp, ndp);
    for (int i = 0; i < d; ++i)
      for (int t = 0; t < 2; ++t) chmin(dp[i][t], 3);
    if (dp[d][n & 1] > 2) return true;
  }
  return false;
}

void yorisou() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  std::ranges::sort(a);
  ll s = std::accumulate(a.begin(), a.end(), 0ll);
  Yes(not(s & 1) and f(a, s / 2));
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}