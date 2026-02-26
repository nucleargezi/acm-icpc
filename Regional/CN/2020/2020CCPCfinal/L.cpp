#include <bits/stdc++.h>
#include <random>
using namespace std;

#define TE template <typename T>
#define fi first
#define se second
#define Z auto
#define all(x) x.begin(), x.end()
#define ep emplace_back
#define eb emplace


#define F1(a) for (int _ = 0; _ < (a); ++_)
#define F2(i, a) for (int i = 0; i < (a); ++i)
#define F3(i, a, b) for (int i = (a); i < (b); ++i)
#define F4(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define OV(a, b, c, d, e, ...) e
#define FOR(...) OV(__VA_ARGS__, F4, F3, F2, F1)(__VA_ARGS__)

#define FF1(a) for (int _ = (a) - 1; _ >= 0; --_)
#define FF2(i, a) for (int i = (a) - 1; i >= 0; --i)
#define FF3(i, a, b) for (int i = (b) - 1; i >= 0; --i)
#define FOR_R(...) OV(__VA_ARGS__, FF3, FF3, FF2, FF1)(__VA_ARGS__)

#define sort ranges::sort

using ll = long long;
using ull = unsigned long long;
TE using vc = vector<T>;
using PII = pair<int, int>;
mt19937 rd(114514);
int rng(int l, int r) {
  return rd() % (r - l) + l;
}

bool chmax(Z &a, Z b) {  return a < b ? a = b, 1 : 0; }

int sol(const vc<PII> &a) {
  int N = a.size();
  int p = rng(0, N);
  map<PII, int> mp;
  FOR(i, N) if (i != p) {
    int x = a[i].fi - a[p].fi, y = a[i].se - a[p].se;
    int g = gcd(x, y);
    x /= g, y /= g;
    if (x < 0 or (x == 0 and y < 0)) x = -x, y = -y;
    ++mp[{x, y}];
  }
  int ans = 0;
  for (Z [x, y] : mp) chmax(ans, y);
  return ans + 1;
}

int n;
void solve() {
  vc<pair<int, int>> a;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
  }
  int s = 0;
  FOR(20) {
    chmax(s, sol(a));
    if (s * 3 >= n * 2) break;
  }
  if (s * 3 < 2 * n) cout << n % 3 << '\n';
  else cout << n - (n - s) * 3 << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  while (cin >> n) solve();
  return 0; 
}