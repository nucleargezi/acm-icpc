#include <iostream>
#include <algorithm>
#include <numeric>

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::set, std::map;

using ll = long long;

bool chmax(auto &x, auto y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(auto &x, auto y) {
  return x > y ? x = y, 1 : 0;
}

vector<ll> fac(ll x) {
  vector<ll> a;
  for (ll i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      a.emplace_back(i);
      if (i != x / i) a.emplace_back(x / i);
    }
  }
  return a;
}

constexpr int N = 1'000'00;
int a[N], fa[N], top, ls[N], rs[N], z[N];

void yorisou() {
  ll n, k;
  cin >> n >> k;
  int mx = -1, mn = 2'000'000'000;
  for (int i = 1; i < n + 1; ++i) {
    cin >> a[i]; 
    chmax(mx, a[i]);
    chmin(mn, a[i]);
  }
  if (mx == mn) return cout << k << ' ' << (k + 1) * k / 2 << '\n', void();

  top = 0;
  for (int i = 1; i < n + 1; ++i) {
    ls[i] = rs[i] = 0;
  }
  for (int i = 1; i < n + 1; ++i) {
    while (top and a[z[top]] > a[i]) ls[i] = z[top], top--;
    fa[i] = z[top];
    fa[ls[i]] = i;
    if (fa[i]) rs[fa[i]] = i;
    z[++top] = i;
  }
  vector<pair<int, int>> v;
  for (int i = 1; i < n + 1; ++i) {
    if (ls[i]) v.emplace_back(i, ls[i]);
    if (rs[i]) v.emplace_back(i, rs[i]);
  }
  
  vector<int> se, nse;
  for (auto [x, y] : v) {
    int a = ::a[x], b = ::a[y];
    if (a > b) swap(a, b);
    if (a == b) continue;

    for (int e : fac(b - a)) {
      int x = e - a;
      if (x >= 1 and x <= k) {
        if ((b + x) % (a + x) == 0) {
          se.emplace_back(x);
        }
      }
    }
    break;
  }

  for (auto [x, y] : v) {
    int a = ::a[x], b = ::a[y];
    if (a > b) swap(a, b);
    if (a == b) continue;
    nse.clear();
    for (int x : se) {
      if (x >= 1 and x <= k) {
        if ((b + x) % (a + x) == 0) {
          nse.emplace_back(x);
        }
      }
    }
    se.swap(nse);
  }
  int c = (int)se.size();
  ll s = 0;
  for (int x : se) s += x;
  cout << c << ' ' << s << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
}