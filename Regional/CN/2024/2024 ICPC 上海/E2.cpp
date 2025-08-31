#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/graph/Apck/bcc_v_e.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests
void Yorisou() {
  INT(n, m);
  graph g(n);
  g.read_graph(m);

  meion [vs, es] = bcc_v_e(g);
  const int N = len(vs);
  int min = n + n, max = -min;
  vector<int> L(n, -1), R(n, -1);
  vector<int> in(n);
  vector<vector<int>> v(n);

  for (int i = 0; i < N; ++i) {
    const meion &ver = vs[i];
    const meion &edges = es[i];
    int sz = len(ver);
    if (sz == 2) continue;
    for (int i : edges) {
      meion &&e = g.edges[i];
      ++in[e.to], ++in[e.f];
      v[e.to].emplace_back(e.f);
      v[e.f].emplace_back(e.to);
    }
    vector<int> go;
    for (int x : ver) {
      if (in[x] > 2) go.emplace_back(x);
    }
    if (not go.empty() and go.size() != 2) iroha No();
    if (not go.empty()) {
      int s = go[0], t = go[1];
      queue<int> q;
      q.emplace_back(s);
      L[s] = 0;
      while (not q.empty()) {
        int n = q.front();
        q.pop();
        for (int t : v[n]) {
          if (L[t] == -1) {
            L[t] = L[n] + 1;
            q.emplace_back(t);
          }
        }
      }
      q.emplace_back(t);
      R[t] = 0;
      while (not q.empty()) {
        int n = q.front();
        q.pop();
        for (int t : v[n]) {
          if (R[t] == -1) {
            R[t] = R[n] + 1;
            q.emplace_back(t);
          }
        }
      }
      for (int x : ver) {
        if (L[x] + R[x] != L[t]) iroha No();
      }
      chmin(sz, L[t] << 1);
    }
    for (int x : ver) {
      in[x] = 0;
      L[x] = -1;
      R[x] = -1;
      v[x].clear();
    }
    chmin(min, sz), chmax(max, sz);
  }
  Yes(min == n + n or min == max);
}
#include "YRS/Z_H/main.hpp"