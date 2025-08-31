#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/dijkstra.hpp"

// #define tests
template <int sigma = 26>
struct PAM {
  struct node {
    array<int, sigma> TO;
    int link;
    int length;
    int fa;
    pair<int, int> pos;
    node(int link = 0, int length = 0, int l = 0, int r = 0)
        : link(link), length(length), pos({l, r}) {
      TO.fill(-1);
      fa = 0;
    }
  };
  using np = node;

  int N;
  vector<np> nodes;
  vector<int> path;
  char off;
  vector<int> dep; // 沿 fail 链的深度（两根为 0）

  template <typename STRING>
  PAM(const STRING &s = {}, char off_ = 'a') : N(len(s)), off(off_) {
    nodes.emplace_back(np(0, -1, 0, -1));
    nodes.emplace_back(np(0, 0, 0, 0));
    dep.assign(2, 0);
    int last = 1;
    path.emplace_back(last);

    meion get_link = [&](int p, int i) {
      while (1) {
        int j = i - 1 - nodes[p].length;
        if (j >= 0 and s[j] == s[i]) return p;
        p = nodes[p].link;
      }
    };

    for (int i = 0; i < N; ++i) {
      int x = s[i] - off;
      int p = get_link(last, i);

      if (nodes[p].TO[x] != -1) {
        last = nodes[p].TO[x];
        path.emplace_back(last);
        continue;
      }

      int q = len(nodes);
      nodes[p].TO[x] = q;
      int l = i - 1 - nodes[p].length;
      int r = i + 1;
      nodes.emplace_back(np(0, r - l, l, r));
      nodes[q].fa = p;

      if (nodes[p].length == -1) {
        nodes[q].link = 1;
      } else {
        int pp = nodes[p].link;
        pp = get_link(pp, i);
        nodes[q].link = nodes[pp].TO[x];
      }

      dep.push_back(dep[nodes[q].link] + 1);

      last = q;
      path.emplace_back(last);
    }
  }
};
void Yorisou() {
  S(s);
  const int n = len(s);
  INT(k, A, B, C, D, E);
  for (char &c : s) {
    if (c >= 'a' and c <= 'z')
      c -= 'a';
    else
      c -= 'A' - 26;
  }
  PAM<52> seg(s, 0);
  const meion &node = seg.nodes;
  const int N = len(node);
  graph<ll, 1> g(N << 1);
  for (int i = 2; i < N; ++i) {
    int fa = node[i].link;
    g.add(i, fa, A);
    g.add(fa, i, B);
  }
  for (int i = 2; i < N; ++i) {
    int x = i;
    for (int j = 1; j < k + 1; ++j) {
      x = node[x].fa;
      if (x <= 1) break;
      g.add(i, x, C);
    }
  }
  for (int i = 2; i < N; ++i) {
    g.add(i, i + N, D);
    g.add(i + N, i, 0);
    if (node[i].fa > 1) {
      g.add(node[i].fa + N, i + N, 0);
    }
  }
  g.build();
  vector dis = dijkstra(g, seg.path.back()).first;
  vector<vector<int>> v(N);
  for (int i = 2; i < N; ++i) v[node[i].link].emplace_back(i);
  static constexpr int LG = 20;
  vector up(N, array<ll, LG>{});
  vector<ll> c(N, inf<ll> / 2);
  meion f = [&](meion &f, int n) -> void {
    for (int i = 1; i < LG; ++i) up[n][i] = up[up[n][i - 1]][i - 1];
    for (int t : v[n]) {
      up[t][0] = n;
      c[t] = std::min(c[n], dis[t] - 1ll * node[t].length * E);
      f(f, t);
    }
  };
  up[0].fill(0);
  up[1].fill(1);
  c[0] = c[1] = inf<ll> / 2;
  f(f, 0);
  f(f, 1);
  
  INT(q);
  while (q--) {
    INT(l, r);
    if (l == 1 and r == n) {
      UL(0);
      continue;
    }
    int L = r - l + 1;
    int p = seg.path[r];
    if (node[p].length > L) {
      for (int k = LG - 1; k >= 0; --k) {
        if (node[up[p][k]].length > L) p = up[p][k];
      }
      p = up[p][0];
    }
    ll ans = node[seg.path.back()].length == n ? 0 : A;
    ans += 1ll * L * E + c[p];
    UL(ans);
  }
}
#include "YRS/Z_H/main.hpp"