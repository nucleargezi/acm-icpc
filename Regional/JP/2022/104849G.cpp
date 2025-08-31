#include <iostream>
#include <algorithm>
#include <ranges>
#include <random>
#include <numeric>

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>

#include <cstring>
#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::pair, std::map, std::set, std::string, std::array, std::queue;

using u8 = unsigned char;
using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

bool chmax(auto &x, auto y) { return x < y ? x = y, 1 : 0; }
bool chmin(auto &x, auto y) { return x > y ? x = y, 1 : 0; }
void Yes(bool f = 1) { cout << (f ? "Yes\n" : "No\n"); }
void No(bool f = 1) { Yes(not f); }
int floor(int x, int y) { return x / y - (x % y and (x ^ y) < 0); }
int ceil(int x, int y) { return floor(x + y - 1, y); }
std::mt19937 rd(0);
uint rng() { return rd(); }
uint rng(uint lim) { return rng() % lim; }
int rng(int l, int r) { return rng() % (r - l) + l; }

struct edge {
  int f, to;
  int w;
  int id;
  edge(int f, int to, int w = 1, int id = -1) : f(f), to(to), w(w), id(id) {}
};
using graph = vector<vector<edge>>;

void yorisou() {
  int n, m;
  cin >> n >> m;
  vector<string> s(n << 1 | 1);
  for (auto &s : s) cin >> s;
  auto I = [&](int x, int y) -> int {
    return x * m + y;
  };
  const int N = n * m;
  graph g(N);
  vector<pair<int, int>> tr;
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < m; ++k) {
      if (k) {
        int x = I(i, k - 1), y = I(i, k);
        if (s[i << 1 | 1][k << 1] == '.') {
          g[x].emplace_back(x, y);
          g[y].emplace_back(y, x);
        } else {
          tr.emplace_back(x, y);
        }
      }
      if (i) {
        int x = I(i - 1, k), y = I(i, k);
        if (s[i << 1][k << 1 | 1] == '.') {
          g[x].emplace_back(x, y);
          g[y].emplace_back(y, x);
        } else {
          tr.emplace_back(x, y);
        }
      }
    }
  }

  auto go = [&](vector<int> st) {
    static constexpr int inf = __INT_MAX__ / 2;
    vector<int> dis(N, inf), fa(N, -1), anc(fa);
    queue<int> q;
    for (int t = 0; int x : st) {
      q.emplace(x);
      dis[x] = 0;
      anc[x] = t++;
    }
    while (not q.empty()) {
      int n = q.front();
      q.pop();
      for (auto &&e : g[n]) {
        if (dis[e.to] == inf) {
          dis[e.to] = dis[n] + 1;
          fa[e.to] = n;
          anc[e.to] = anc[n];
          q.emplace(e.to);
        }
      }
    }
    return std::tuple{dis, fa, anc};
  };
  auto [dis, fa, _] = go({I(0, 0)});
  int t = I(n - 1, m - 1);
  vector<int> path;
  int x = t;
  while (x != -1) path.emplace_back(x), x = fa[x];
  auto [sid, __, anc] = go(path);
  int ans = dis[t] + 1;
  for (auto [x, y] : tr) {
    int fx = anc[x], fy = anc[y];
    if (fx == fy) continue;
    chmax(ans, dis[t] + sid[x] + sid[y] - std::abs(fx - fy) + 2);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}