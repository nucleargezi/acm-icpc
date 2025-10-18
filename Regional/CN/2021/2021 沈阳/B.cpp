#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FO(i, n) for (int i = 0; i < (n); ++i)
#define fi first
#define se second
#define Z auto
#define ep emplace_back
#define eb emplace

using ll = long long;
using u8 = unsigned char;

void yorisou() {
  int N, M;
  cin >> N >> M;
  vector<tuple<int, int, int>> e(M);
  for (Z &[x, y, w] : e) {
    cin >> x >> y >> w;
    --x, --y;
  }
  
  ll ans = 0;
  bool ok = true;
  for (int i = 0; i < 30 and ok; ++i) {
    vector<vector<pair<int, int>>> v(N);
    for (Z [x, y, w] : e) {
      int t = w >> i & 1;
      v[x].ep(y, t);
      v[y].ep(x, t);
    }
    vector<char> vis(N, -1);
    int s, w;
    Z f = [&](Z &f, int n) -> void {
      ++s;
      w += (vis[n] == 0);
      for (Z [t, w] : v[n]) {
        if (vis[t] != -1) {
          if (vis[t] != (vis[n] ^ w)) ok = false;
        } else {
          vis[t] = vis[n] ^ w;
          f(f, t);
        }
      }
    };
    FO(k, N) if (vis[k] == -1) {
      s = 0, w = 0;
      vis[k] = 0;
      f(f, k);
      ans += std::min(w, s - w) * (1ll << i);
    }
  }
  cout << ((not ok) ? -1 : ans) << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while (T--) yorisou();
  return 0;
}