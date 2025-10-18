#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ep emplace_back
#define eb emplace
#define Z auto
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define len(a) (int)(a.size())

using ll = long long;

bool chmax(Z &x, Z y) {
  return x < y ? x = y, 1 : 0;
}
bool chmin(Z &x, Z y) {
  return x > y ? x = y, 1 : 0;
}

int LB(const Z &a, Z x) { return lower_bound(a, x) - a.begin(); }
int UB(const Z &a, Z x) { return upper_bound(all(a), x) - a.begin(); }

void yorisou() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<tuple<int, int, int>>> v(N);
  FOR(i, 0, M) {
    int x, y, c, w;
    cin >> x >> y >> c >> w;
    --x, --y, --c;
    v[x].ep(y, c, w);
    v[y].ep(x, c, w);
  }
  FOR(i, 0, N) sort(all(v[i]));
  using T = pair<ll, int>;
  vector<priority_queue<T, vector<T>, greater<T>>> q(M);
  for (Z [t, c, w] : v[0]) {
    q[c].eb(w, t);
  }
  string ans(N, '0');
  ans[0] = '1';
  FOR(i, 0, K) {
    int a, b;
    cin >> a >> b;
    --a;
    priority_queue<T, vector<T>, greater<T>> que;
    while (not q[a].empty() and q[a].top().fi <= b) {
      que.eb(q[a].top());
      q[a].pop();
    }
    vector<int> go;
    while (not que.empty() and que.top().fi <= b) {
      Z [dis, n] = que.top();
      que.pop();
      if (ans[n] == '1') continue;
      ans[n] = '1';
      go.ep(n);
      for (Z [t, c, w] : v[n]) {
        if (ans[t] == '1') continue;
        if (c != a or dis + w > b) continue;
        que.eb(dis + w, t);
      }
    }
    for (Z n : go) {
      for (Z [t, c, w] : v[n]) {
        q[c].eb(w, t);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  int T = 1;
  cin >> T;
  while (T--) yorisou();
}