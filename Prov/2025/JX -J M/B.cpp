#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, Q);
  VEC(string, s, N - 1);
  FOR(i, N - 1) for (char &c : s[i]) c -= '0';
  vector<vector<int>> v(N);
  FOR(i, N - 1) FOR(k, N - i - 1) {
    if (s[i][k]) {
      v[i].ep(i + k + 1);
    } else {
      v[i + k + 1].ep(i);
    }
  }

  queue<PII> q;
  vector<u8> vis(N);
  vector<int> st;
  static char go[5000][5000];
  static bool bt[5000][5000];
  FOR(i, N) FOR(k, N) go[i][k] = -2;
  FOR(i, N) for (int t : v[i]) bt[i][t] = 1;
  FOR(Q) {
    INT(x, y);
    --x, --y;
    if (go[x][y] != -2) {
      print((int)go[x][y]);
      continue;
    }
    q.clear();
    q.eb(0, x);
    st.clear();
    int ans = -1;
    st.ep(x);
    vis[x] = 1;
    while (not q.empty() and ans == -1) {
      Z [d, n] = q.pop();
      if (bt[n][y]) {
        ans = d;
        break;
      }
      for (int t : v[n]) if (not vis[t]) {
        vis[t] = 1;
        if (d < 5) q.eb(d + 1, t), st.ep(t);
      }
    }
    print(int(go[x][y] = ans));
    for (int x : st) vis[x] = 0;
  }
}
#include "YRS/Z_H/main.hpp"