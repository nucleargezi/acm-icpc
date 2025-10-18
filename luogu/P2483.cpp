#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
#include "MeIoN_Lib/ds/basic/queue.hpp"
#include "MeIoN_Lib/ds/heap/leftest_heap.hpp"
#include "MeIoN_Lib/graph/Apck/dijkstra.hpp"
#include "MeIoN_Lib/graph/Apck/reverse.hpp"
using RE = long double;
template <typename T, typename GT, RE eps = 1e-6L>
int P2483(GT& g, int s, int t, T lim) {
  int N = g.n;
  GT RG = reverse_graph(g);
  meion [dis, fa] = dijkstra<T, GT>(RG, t);
  if (dis[s] == inf<T>) iroha 0;
  vector<vector<int>> tr(N);
  FOR(i, N) if (fa[i] != -1) tr[fa[i]].emplace_back(i);
  using HP = leftistHeap<T, int>;
  vector<HP*> h(N, nullptr);
  queue<int> q;
  q.emplace_back(t);
  while (not q.empty()) {
    int n = q.pop();
    bool done = 0;
    for (meion &&e : g[n]) {
      if (dis[e.to] == inf<T>) continue;
      const T cost = e.cost + dis[e.to] - dis[n];
      if (not done and e.to == fa[n] and cost == 0) {
        done = 1;
        continue;
      }
      h[n] = HP::insert(h[n], cost, e.to);
    }
    for (int x : tr[n]) {
      h[x] = h[n];
      q.emplace_back(x);
    }
  }
  if (not h[s]) {
    if (dis[s] > lim + eps) iroha 0;
    iroha 1;
  }
  min_heap<pair<T, HP*>> que;
  que.emplace(dis[s] + h[s]->key, h[s]);
  RE sum = dis[s];
  ll ans = 1;
  while (not que.empty()) {
    meion [dis, n] = pop(que);
    sum += dis;
    if (sum > lim + eps) break;
    ++ans;
    if (h[n->value]) que.emplace(dis + h[n->value]->key, h[n->value]);
    if (n->left) que.emplace(dis + n->left->key - n->key, n->left);
    if (n->right) que.emplace(dis + n->right->key - n->key, n->right);
  }
  iroha ans;
}
void Yorisou() {
  LL(n, m);
  REA(Lim);
  graph<RE, 1> g(n);
  FOR(m) {
    LL(x, y);
    --x, --y;
    REA(w);
    if (x == n - 1) {
      continue;
    }
    g.add(x, y, w);
  }
  g.build();
  UL(P2483<RE>(g, 0, n - 1, Lim));
}
#include "MeIoN_Lib/Z_H/main.hpp"