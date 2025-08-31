#include <cstring>
#include <iostream>
#include <algorithm>

#include <map>
#include <set>
#include <vector>
#include <array>
#include <queue>
#include <bitset>

#include <ranges>
#include <format>

#include <cassert>

using std::cin, std::cout, std::swap;
using std::vector, std::array, std::queue, std::bitset, std::set, std::map;
using std::deque;

using ll = long long;

vector<int> minp, prims;
void sieve(int n) {
  minp.assign(n + 1, 0);
  for (int i = 2; i < n + 1; ++i) {
    if (not minp[i]) {
      minp[i] = i;
      prims.emplace_back(i);
    }
    for (int p : prims) {
      if (i * p > n) break;
      minp[i * p] = p;
      if (p == minp[i]) break;
    }
  }
}

namespace FL {
const int V = 1e6;
const int M = 3e6;
const int inf = 0x3f3f3f3f;
int n, m, s, t, p, maxflow, mincost;
class Graph {
 public:
  int top, to[M << 1], fw[M << 1], ct[M << 1];
  vector<int> g[V];
  Graph() { top = 1; }
  void ins(int x, int y, int f, int c) {
    g[x].push_back(++top);
    to[top] = y, fw[top] = f, ct[top] = c;
  }
  void add(int x, int y, int f, int c) { ins(x, y, f, c), ins(y, x, 0, -c); }
};
class zkwMCMF : public Graph {
 public:
  int dep[V];
  bool vis[V];
  deque<int> q;
  bool spfa() {
    for (int i = 1; i <= p; i++) vis[i] = 0, dep[i] = inf;
    q.push_back(t), vis[t] = 1, dep[t] = 0;
    while (q.size()) {
      int x = q.front();
      q.pop_front(), vis[x] = 0;
      for (auto i : g[x])
        if (fw[i ^ 1] && dep[to[i]] > dep[x] - ct[i]) {
          dep[to[i]] = dep[x] - ct[i];
          if (!vis[to[i]]) {
            vis[to[i]] = 1;
            if (q.size() && dep[to[i]] < dep[q.front()])
              q.push_front(to[i]);
            else
              q.push_back(to[i]);
          }
        }
    }
    return dep[s] < inf;
  }
  int dfs(int x, int F) {
    vis[x] = 1;
    if (x == t || !F) return F;
    int f, flow = 0;
    for (auto i : g[x])
      if (!vis[to[i]] && fw[i] && dep[x] - ct[i] == dep[to[i]] &&
          (f = dfs(to[i], std::min(F, fw[i]))) > 0) {
        mincost += f * ct[i], fw[i] -= f, fw[i ^ 1] += f, flow += f, F -= f;
        if (!F) break;
      }
    return flow;
  }
  void work() {
    while (spfa()) {
      vis[t] = 1;
      while (vis[t]) {
        for (int i = 1; i <= p; i++) vis[i] = 0;
        maxflow += dfs(s, inf);
      }
    }
  }
} mcf;
}  // namespace FL

vector<int> fac[300];
vector<int> cost[300];


void yorisou() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0, x; i < n; ++i) {
    cin >> x;
    a[i] = x;
    for (int k = 1; k * k <= x; ++k) {
      if (x % k == 0) {
        fac[i].emplace_back(k);
        fac[i].emplace_back(x / k);
      }
    }
    std::ranges::sort(fac[i]);
    fac[i].erase(std::unique(fac[i].begin(), fac[i].end()), fac[i].end());
    const int M = fac[i].size();
    for (int k = 0; k < M; ++k) {
      int d = x / fac[i][k];
      int c = 0;
      for (int e : prims) {
        if (e > d) break;
        while (d % e == 0) {
          ++c;
          d /= e;
        }
      }
      if (d != 1) ++c;
      cost[i].emplace_back(c);
    }
  }
  vector<int> vs;
  for (int i = 0; i < n; ++i) {
    for (int x : fac[i]) vs.emplace_back(x);
  }
  std::ranges::sort(vs);
  vs.erase(std::unique(vs.begin(), vs.end()), vs.end());

  int al = n + vs.size();
  FL::s = al + 1, FL::t = al + 2;
  FL::p = al + 2;

  for (int i = 0; i < n; ++i) {
    const int M = fac[i].size();
    for (int k = 0; k < M - 1; ++k) {
      int x = fac[i][k];
      int c = cost[i][k];
      int id = std::lower_bound(vs.begin(), vs.end(), x) - vs.begin();
      id += 1;
      FL::mcf.add(i + 1, n + id, 1, 50 - c);
    }
    int x = a[i];
    int id = std::lower_bound(vs.begin(), vs.end(), x) - vs.begin();
    id += 1;
    FL::mcf.add(i + 1, n + id, 1, 50);
  }
  
  for (int i = 0; i < n; ++i) {
    FL::mcf.add(al + 1, i + 1, 1, 0);
  }
  for (int i = 0; i < (int)vs.size(); ++i) {
    FL::mcf.add(i + 1 + n, al + 2, 1, 0);
  }
  FL::mcf.work();
  cout << FL::maxflow * 50 - FL::mincost << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  sieve(1'000'00);
  while (T--) yorisou();
  return 0;
}