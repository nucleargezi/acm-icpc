#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/mod/mint_t.hpp"

using mint = M99;
void Yorisou() {
  STR(s, p);
  reverse(s);
  reverse(p);
  for (char &c : s) c -= 'a';
  for (char &c : p) c -= 'a';
  sam ss(si(s));
  ss.build(s);

  int n = si(ss);
  vc<vc<int>> g = ss.build_dir_g();
  vc<char> vis(n);
  vc<int> cut(n);
  int t = 0;
  for (int c : p) {
    t = ss[t][c];
    if (t == -1) break;
  }
  if (t != -1) {
    vc<int> dis(n, -1), q{t};
    dis[t] = 0;
    FOR(i, si(q)) {
      int n = q[i], d = dis[n];
      if (n and ss[n].sz >= si(p) + d and ss[ss[n].fa].sz < si(p) + d) {
        vis[n] = 1;
        cut[n] = d + si(p) - ss[ss[n].fa].sz;
      }
      FOR(c, 26) {
        int x = ss[n][c];
        if (x == -1 or dis[x] != -1) continue;
        dis[x] = d + 1;
        q.ep(x);
      }
    }
  }
  vc<int> q{0};
  FOR(i, si(q)) {
    int n = q[i];
    if (vis[n]) continue;
    for (int x : g[n]) q.ep(x);
  }
  vc<mint> dp(n);
  FOR_R(i, si(q)) {
    int n = q[i];
    if (not vis[n]) {
      dp[n] = 1;
      for (int x : g[n]) dp[n] *= dp[x];
      if (ss[n].fa != -1) dp[n] += ss[n].sz - ss[ss[n].fa].sz;
    } else {
      dp[n] = cut[n];
    }
  }
  print(dp[0] - 1);
}

int main() {
  Yorisou();
  return 0;
}