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

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::map, std::set, std::string;

bool chmax(auto &x, auto y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(auto &x, auto y) {
  return x > y ? x = y, 1 : 0;
}

void yorisou() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  for (auto &[l, r] : a) {
    cin >> l >> r;
  }
  vector<int> I(n);
  for (int i = 0; i < n; ++i) I[i] = i;
  std::ranges::sort(I, [&](int x, int y) -> bool { return a[x] < a[y]; });
  vector<int> ans(n);
  std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> q;
  for (int i = 1, p = 0; i < 32; ++i) {
    while (p < n and a[I[p]].first <= i) {
      int id = I[p++];
      q.emplace(a[id].second, id);
    }
    for (int j = 0; j < k and not q.empty(); ++j) {
      auto [r, id] = q.top();
      q.pop();
      ans[id] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}