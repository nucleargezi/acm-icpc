#include <iostream>
#include <algorithm>
#include <numeric>
#include <bit>

#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <set>

#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::string;

using ll = long long;

bool chmax(auto &x, auto y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(auto &x, auto y) {
  return x > y ? x = y, 1 : 0;
}
int topbit(int x) {
  return (x == 0 ? -1 : 31 - __builtin_clz(x));
}
using X = int;
X op(X a, X b) { return std::max(a, b); }
X unit() { return 0; }
struct st {
  int n, log;
  vector<vector<X>> dat;

  st(int n, auto f) {
    build(n, f);
  }
  
  void build(int N, auto f) {
    n = N, log = 1;
    while ((1 << log) < n) ++log;
    dat.resize(log);
    dat[0].resize(n);
    for (int i = 0; i < n; ++i) dat[0][i] = f(i);

    for (int i = 0; i < log - 1; ++i) {
      int sz = dat[i].size();
      sz -= 1 << i;
      dat[i + 1].resize(sz);
      for (int k = 0; k < sz; ++k) {
        dat[i + 1][k] = op(dat[i][k], dat[i][k + (1 << i)]);
      }
    }
  }

  X prod(int l, int r) {
    if (l == r) return unit();
    if (r == l + 1) return dat[0][l];
    int k = topbit(r - l - 1);
    return op(dat[k][l], dat[k][r - (1 << k)]);
  }
};

constexpr ll mod = 998244353;
constexpr ll inf = 9223372036854775807LL;

pair<ll, ll> merge(pair<ll, ll> a, pair<ll, ll> b) {
  if (b.first != a.first) return std::min(a, b);
  return pair<ll, ll>{a.first, (a.second + b.second) % mod};
}

int binary(auto f, int l, int r) {
  while (std::abs(r - l) > 1) {
    int x = (l + r) >> 1;
    (f(x) ? l : r) = x;
  }
  return l;
}
void yorisou() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int &x : a) cin >> x;
  for (int &x : b) cin >> x;
  int k;
  cin >> k;
  vector<int> c(k);
  for (int &x : c) cin >> x;

  vector<int> v(m + 1, -1);
  for (int i = 0; i < n; ++i) {
    chmax(v[b[i]], a[i]);
  }
  vector<pair<int, int>> e;
  for (int i = 1; i < m + 1; ++i) {
    if (v[i] != -1) {
      e.emplace_back(i, v[i]);
    }
  }
  sort(e.begin(), e.end());
  const int N = e.size(), mx = e.back().first + 1;
  st seg(N, [&](int i) {
    return e[i].second;
  });
  vector<int> cov(mx); // [0, cov[i])
  for (int i = 0; i < mx; ++i) {
    int x = binary([&](int x) -> bool {
      if (x == -1) return true;
      return e[x].first <= i;
    }, -1, N) + 1;
    cov[i] = x;
  }
  vector<std::unordered_map<int, pair<ll, ll>>> dp(mx);
  dp[0][0] = {0, 1};
  for (int i = 0; i < mx - 1; ++i) {
    for (auto [hp, v] : dp[i]) {
      int l = cov[i];
      for(int atk = 1; atk < k + 1; ++atk) {
        int kl = std::min(mx - 1, i + atk);
        int r = cov[kl];
        int nhp = std::max(hp - atk, seg.prod(l, r));
        if (not dp[kl].contains(nhp)) {
          dp[kl][nhp] = {v.first + c[atk - 1], v.second};
        } else {
          auto &x = dp[kl][nhp];
          x = merge(x, {v.first + c[atk - 1], v.second});
        }
      }
    }
  }

  vector<pair<ll, ll>> f(m + 1, pair<ll, ll>{inf, inf});
  for (auto [hp, c] : dp.back()) {
    f[hp] = c;
  }
  for (int i = m; i >= 0; i--) if (f[i] != pair{inf, inf}) {
    for (int atk = 1; atk < k + 1; ++atk) {
      auto [cost, ways] = f[i];
      int go = std::max(0, i - atk);
      f[go] = merge(f[go], pair{cost + c[atk - 1], ways});
    }
  }
  auto [cost, ways] = f[0];
  cout << cost << ' ' << ways << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) yorisou();
  return 0;
}