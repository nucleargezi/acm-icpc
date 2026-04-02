#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FO(i, n) for (int i = 0; i < (n); ++i)
#define fi first
#define se second
#define Z auto
#define ep emplace_back
#define eb emplace
#define all(a) a.begin(), a.end()
using ll = long long;
using u8 = unsigned char;
using AR = array<int, 4>;

bool chmin(Z &x, Z y) {
  return x > y ? x = y, 1 : 0;
}
bool chmax(Z &x, Z y) {
  return x < y ? x = y, 1 : 0;
}

void yorisou() {
  int N, M;
  cin >> N >> M;
  vector<vector<pair<int, int>>> v(N);
  vector<int> e(M);
  vector<pair<int, int>> LR(M);
  FOR(i, 0, M) {
    int x, y;
    cin >> x >> y >> e[i];
    --x, --y;
    LR[i] = {x, y};
    v[x].ep(y, i);
    v[y].ep(x, i);
  }

  vector<int> dfn(N, -1), low(N, -1);
  vector<u8> vis(N), is(M);
  int tot = 0;
  vector<int> sz(N);
  Z f = [&](Z &f, int n, int fa) -> void {
    dfn[n] = low[n] = tot++;
    vis[n] = 1;
    int s = 0;
    for (Z [to, id] : v[n]) {
      if (id == fa) continue;
      if (not vis[to]) {
        ++s;
        f(f, to, id);
        s += sz[to];
        chmin(low[n], low[to]);
        if (low[to] > dfn[n]) {
          is[id] = 1;
        }
      } else {
        if (dfn[to] < dfn[n]) ++s;
        chmin(low[n], dfn[to]);
      }
    }
    sz[n] = s;
  };
  FOR(i, 0, N) if (not vis[i]) f(f, i, -1);
  if (~M & 1) {
    cout << accumulate(all(e), 0ll) << '\n';
  } else {
    ll ans = 0;
    ll s = accumulate(all(e), 0ll);
    FOR(i, 0, M) {
      if (not is[i]) {
        chmax(ans, s - e[i]);
      } else {
        Z [x, y] = LR[i];
        int mn = min(sz[x], sz[y]);
        if (~mn & 1) chmax(ans, s - e[i]);
      }
    }
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}