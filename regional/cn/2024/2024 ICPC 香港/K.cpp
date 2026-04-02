#include <iostream>
#include <algorithm>
#include <numeric>

#include <vector>
#include <string>
#include <map>
#include <set>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::string;

vector<pair<int, int>> runlen(const string &s) {
  vector<pair<int, int>> v;
  for (char c : s) {
    if (v.empty() or v.back().first != c) v.emplace_back(c, 1);
    else v.back().second += 1;
  }
  return v;
}

void yorisou() {
  string s;
  cin >> s;
  auto seg = runlen(s);
  const int n = seg.size();
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    auto quis = runlen(t);
    int l = 0, r = n;
    bool ok = 1;
    for (auto [e, c] : quis) {
      while (c > 0) {
        if (l >= r) {
          ok = 0;
          break;
        }
        if (seg[l].first == e) c -= seg[l].second;
        ++l;
      }
      if (not ok) break;
    }
    if (t[0] == 'R' and s[0] == 'L') ok = 0;
    if (t.back() == 'L' and s.back() == 'R') ok = 0;
    cout << (ok ? "YES\n" : "NO\n");
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
  return 0;
}