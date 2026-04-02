#include <iostream>
#include <algorithm>

#include <map>
#include <set>
#include <vector>
#include <array>
#include <queue>
#include <bitset>

#include <ranges>

#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::array, std::queue, std::bitset, std::set, std::map;

using ll = long long;

void yorisou() {
  int n, m, q;
  cin >> n >> m >> q;
  set<int> se;
  int cp = 0;
  int sc = m;
  vector<ll> c(m);
  while (q--) {
    int op, id, x;
    cin >> op;
    if (op == 1) {
      cin >> x;
      cp = x;
      sc = m;
      se.clear();
    } else if (op == 2) {
      cin >> id >> x;
      --id;
      if (cp == x and se.emplace(id).second) {
        c[id] += sc--;
      }
    } else if (op == 3) {
      cin >> id >> x;
      --id;
      if (cp == x and se.emplace(id).second) {
        ;
      }
    }
  }
  vector<int> I(m);
  for (int i = 0; i < m; ++i) I[i] = i;
  std::ranges::sort(I, [&](int i, int k) -> bool {
    return c[i] > c[k] or (c[i] == c[k] and i < k);
  });
  for (int i = 0; i < m; ++i) {
    cout << I[i] + 1 << ' ' << c[I[i]] << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
  return 0;
}