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

using ll = long long;

bool chmax(auto &x, auto y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(auto &x, auto y) {
  return x > y ? x = y, 1 : 0;
}

int Q(ll x) {
  cout << "query " << x << std::endl;
  int s;
  cin >> s;
  return s;
}
void A(ll x) {
  cout << "answer " << x << std::endl;
}

ll binary(const auto &f, ll l, ll r) {
  while (std::abs(r - l) > 1) {
    ll x = (l + r) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}

void yorisou() {
  int al = Q(0);
  constexpr int N = 18;
  ll c[N];
  c[0] = 1;
  for (int i = 1; i < N; ++i) c[i] = c[i - 1] * 10;
  ll ans = 0;
  for (int i = 0; i < N; ++i) {
    int dis = binary([&](int x) -> bool {
      if (not x) return 1;
      int d = Q(c[i] * x);
      return d == x + al;
    }, 0, 10);
    ans += (9 - dis) % 10 * c[i];
  }
  A(ans);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}