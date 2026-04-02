#include <bits/stdc++.h>
using namespace std;

#define eb emplace
#define ep emplace_back
#define Z auto
#define all(a) a.begin(), a.end()
#define F(a) for (int i = 0; i < (a); ++i)
#define FF(i, a) for (int i = 0; i < (a); ++i)
#define FFF(i, a, b) for (int i = (a); i < (b); ++i)
#define OV(a, b, c, d, ...) d
#define FOR(...) OV(__VA_ARGS__, FFF, FF, F)(__VA_ARGS__)

using ll = long long;

void sol() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(N);
  FOR(M) {
    int x, y;
    cin >> x >> y, --x, --y;
    g[x].ep(y), g[y].ep(x);
  }
  vector<vector<int>> ng(N << 1);
  vector<int> dfn(N), low(N), st;
  vector<char> vis(N);
  int nx = N, k = 0;
  vector<pair<int, int>> es;
  Z f = [&](Z &f, int n, int fa) -> void {
    st.ep(n);
    low[n] = dfn[n] = k++;
    vis[n] = 1;
    int ch = 0;
    for (int to : g[n]) if (to != fa) {
      if (not vis[to]) {
        ++ch;
        int sl = st.size();
        f(f, to, n);
        low[n] = min(low[n], low[to]);
        if ((fa == -1 and ch > 1) or (fa != -1 and low[to] >= dfn[n])) {
          es.ep(nx, n);
          while ((int)st.size() > sl) {
            es.ep(nx, st.back());
            st.pop_back();
          }
          ++nx;
        }
      } else {
        low[n] = min(low[n], dfn[to]);
      }
    }
  };
  f(f, 0, -1);
  for (int x : st) es.ep(nx, x);
  ++nx;
  for (Z [x, y] : es) 
    ng[x].ep(y), ng[y].ep(x);
  vector<int> in(N << 1);
  FOR(i, N) for (int t : ng[i]) ++in[t];
  vector<int> ans;
  FOR(i, N) {
    int c = 0, f = 1;
    for (int t : ng[i]) c += in[t] > 2, f &= in[t] > 2;
    if (c > 1 and f) ans.ep(i + 1);
  }
  if (ans.empty()) cout << "Empty\n";
  else {
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(0);
  int T = 1;
  cin >> T;
  while (T--) sol();
  return 0;
}