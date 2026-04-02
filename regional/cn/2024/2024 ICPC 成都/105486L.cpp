#include <iostream>
#include <algorithm>

#include <map>
#include <set>
#include <vector>
#include <array>
#include <queue>
#include <bitset>

#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::array, std::queue, std::bitset, std::set, std::map;

void yorisou() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> ans(100, a);
  for (int i = 50; i < 95; ++i) ans[i] = b;
  for (int i = 95; i < 100; ++i) ans[i] = c;
  ans[99] += 1;
  cout << 100 << '\n';
  for (int i = 0; i < 100; ++i) {
    cout << ans[i] << " \n"[i + 1 == 100];
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}