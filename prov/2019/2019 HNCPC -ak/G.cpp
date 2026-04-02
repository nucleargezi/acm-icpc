#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/basic/retsu.hpp"

// #define tests
using A = retsu<int>;
int N, M;
void yorisou() {
  A a(N, M);
  FOR(i, N) FOR(k, M) IN(a[i][k]);
  vector<int> c(M);
  vector<vector<int>> g(M), ng(N - 1);
  FOR(i, N - 1) FOR(k, M) {
    if (a[i][k] > a[i + 1][k]) {
      ++c[k];
      ng[i].ep(k);
    } else if (a[i][k] < a[i + 1][k]) {
      g[k].ep(i);
    }
  }

  min_heap<int> q;
  FOR(i, M) if (not c[i]) q.eb(i);
  vector<u8> vis(M), re(N - 1);
  vector<int> I;
  while (not q.empty()) {
    int k = pop(q);
    if (vis[k]) continue;
    vis[k] = 1;
    I.ep(k);
    for (int i : g[k]) {
      if(re[i]) continue;
      re[i] = 1;
      for (int k : ng[i]) {
        if (--c[k] == 0) q.eb(k);
      }
    }
  }
  if (len(I) != M) return print(-1);
  for (int &x : I) ++x;
  print(I);
}
void Yorisou() {
  while (IN(N, M)) yorisou();
}
#include "YRS/Z_H/main.hpp"