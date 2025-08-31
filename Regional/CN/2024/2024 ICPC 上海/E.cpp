#include <iostream>
#include <algorithm>

#include <vector>
#include <queue>
#include <bitset>

using std::cin, std::cout, std::swap;
using std::vector, std::array, std::bitset, std::pair, std::queue;

using u8 = unsigned char;
using ll = long long;

bool chmax(auto &x, const auto &y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(auto &x, const auto &y) {
  return x > y ? x = y, 1 : 0;
}

void yorisou() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }
  
  vector<int> dfn(n), low(n), st;
  vector<u8> vis(n);
  vector<pair<int, int>> est;
  int nxt = n;
  int k = 0;
  vector<pair<int, int>> edges;
  vector<vector<pair<int, int>>> bedge((n + 10) << 1);
  auto f = [&](auto &f, int n, int fa) -> void {
    st.emplace_back(n);
    low[n] = dfn[n] = k++;
    vis[n] = 1;
    int ch = 0;
    for (int x : v[n]) {
      if (x == fa) continue;
      if (not vis[x]) {
        ++ch;
        int slen = (int)st.size();
        est.emplace_back(n, x);
        f(f, x, n);
        chmin(low[n], low[x]);
        if ((fa == -1 and ch > 1) or (fa != -1 and low[x] >= dfn[n])) {
          edges.emplace_back(nxt, n);
          while ((int)st.size() > slen) {
            edges.emplace_back(nxt, st.back());
            st.pop_back();
          }
          while (not est.empty()) {
            auto [a, b] = est.back();
            est.pop_back();
            bedge[nxt].emplace_back(a, b);
            if ((a == n and b == x) or (a == x and b == n))
              break;
          }
          ++nxt;
        }
      } else {
        chmin(low[n], dfn[x]);
        if (dfn[x] < dfn[n]) est.emplace_back(n, x);
      }
    }
  };
  for (int i = 0; i < n; ++i) if (not vis[i]) {
    f(f, i, -1);
    if (not st.empty()) {
      for (int x : st) {
        edges.emplace_back(nxt, x);
      }
      st.clear();
      for (auto [x, y] : est) {
        bedge[nxt].emplace_back(x, y);
      }
      est.clear();
      ++nxt;
    }
  }
  vector<vector<int>> bct(nxt);
  for (auto [x, y] : edges) {
    bct[x].emplace_back(y);
    bct[y].emplace_back(x);
  }
  int min = n + n, max = -min;
  vector<int> dis(n, -1), sid(n, -1);
  vector<int> in(n);
  vector<vector<int>> ng(n);
  for (int i = n; i < nxt; ++i) {
    int sz = (int)bct[i].size();
    if (sz == 2) continue;
    vector<int> vs;
    for (auto [x, y] : bedge[i]) {
      vs.emplace_back(x);
      vs.emplace_back(y);
      ++in[x], ++in[y];
      ng[x].emplace_back(y);
      ng[y].emplace_back(x);
    }
    vector<int> go;
    std::sort(vs.begin(), vs.end());
    vs.erase(std::unique(vs.begin(), vs.end()), vs.end());
    for (int x : vs) {
      if (in[x] > 2) go.emplace_back(x);
    }
    if (go.size() != 0 and go.size() != 2) return cout << "No\n", void();
    if (not go.empty()) {
      int s = go[0], t = go[1];
      queue<int> q;
      q.emplace(s);
      dis[s] = 0;
      while (not q.empty()) {
        int n = q.front();
        q.pop();
        for (int t : ng[n]) {
          if (dis[t] == -1) {
            dis[t] = dis[n] + 1;
            q.emplace(t);
          }
        }
      }
      q.emplace(t);
      sid[t] = 0;
      while (not q.empty()) {
        int n = q.front();
        q.pop();
        for (int t : ng[n]) {
          if (sid[t] == -1) {
            sid[t] = sid[n] + 1;
            q.emplace(t);
          }
        }
      }
      for (int x : vs) {
        if (dis[x] + sid[x] != dis[t]) {
          return cout << "No\n", void();
        }
      }
      chmin(sz, dis[t] << 1);
    }
    for (int x : vs) {
      in[x] = 0;
      dis[x] = -1;
      sid[x] = -1;
      ng[x].clear();
    }
    chmin(min, sz);
    chmax(max, sz);
  }
  if (min != n + n) cout << (min == max ? "Yes" : "No") << '\n';
  else cout << "Yes" << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  cin >> T;
  while (T--) {
    yorisou();
  }
  return 0;
}