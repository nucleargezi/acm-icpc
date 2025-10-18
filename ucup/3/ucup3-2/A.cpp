#include <bits/stdc++.h>
using namespace std;

#define Z auto
#define all(x) x.begin(), x.end()

int topbit(int x) { return x == 0 ? -1 : 31 - __builtin_clz(x); }

void yorisou() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> v(N), vv(N);
  vector<int> in(N);
  vector<char> vis(N), vvis(N);
  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    v[x].emplace_back(y);
    vv[y].emplace_back(x);
    ++in[x];
  }
  queue<int> q;
  q.emplace(0);
  vis[0] = 1;
  while (not q.empty()) {
    int n = q.front();
    q.pop();
    for (int x : v[n]) {
      if (not vis[x]) vis[x] = 1, q.emplace(x);
    }
  }
  q.emplace(N - 1);
  vvis[N - 1] = 1;
  while (not q.empty()) {
    int n = q.front();
    q.pop();
    for (int x : vv[n]) if (not vvis[x]) vvis[x] = 1, q.emplace(x);
  }
  if (not vis[N - 1]) return cout << 0 << '\n', void();
  int ans = 0;
  for (int i = 0; i < N - 1; ++i)
    if (vis[i] and vvis[i]) {
      for (int x : v[i]) {
        if (vis[x] and vvis[x]) ++ans;
      }
      --ans;
    }
  cout << ans + 1 << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}