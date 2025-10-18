#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/Basic.hpp"
#include "YRS/graph/Apck/block_cut_tree.hpp"

#define tests
void Yorisou() {
  INT(N, M);
  graph g(N);
  g.read_graph(M);
  Z ng = block_cut(g);
  vector<int> sz(ng.N);
  FOR(i, N) sz[i] = 1;
  Z f = [&](Z &f, int n, int fa) -> void {
    for (Z &&e : ng[n]) {
      if (e.to == fa) continue;
      f(f, e.to, n);
      sz[n] += sz[e.to];
    }
  };
  f(f, 0, -1);

  ll ans = 0;
  FOR(i, N, ng.N) {
    vector<int> v;
    for (Z &&e : ng[i]) v.ep(e.to);
    const int ln = len(v);
    if (ln == 2) {
      int x = v[0], y = v[1];
      int c = std::min(sz[x], sz[y]);
      ans += std::min(c, N - c);
    } else {
      vector<int> s(ln);
      FOR(i, ln) s[i] = sz[v[i]];
      int mx = QMAX(s);
      FOR(i, ln) if (s[i] == mx) s[i] = N - SUM(s) + mx;

      v.insert(v.end(), all(v));
      s.insert(s.end(), all(s));
      v.ep(v[0]);
      s.ep(s[0]);
      int k = 0, ss = 0;
      ll add = 0;
      FOR(i, ln) {
        while (s[i]) {
          while (ss <= N / 2) ss += s[k++];
          int d = std::min(s[i], ss - N / 2);
          int dis = k - i - 1;
          chmin(dis, ln - dis);
          add += 1ll * d * dis;
          s[i] -= d;
          ss -= d;
        }
      }
      ans += add >> 1;
    }
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"