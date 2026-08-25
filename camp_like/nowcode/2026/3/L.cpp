#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

int N, M;
int id(int a, int b) { return a * M + b; }

void Yorisou() {
  IN(N, M);
  RET(int, a, N, M);
  vc<vc<int>> g(N * M);
  vc<int> in(N * M);
  Z ad  = [&](int a, int b) {
    g[a].ep(b);
    ++in[b];
  };
  FOR(i, N) FOR(k, M) {
    int x = a[i][k];
    if (i) {
      if (a[i - 1][k] > x) {
        ad(id(i, k), id(i - 1, k));
      } else if (a[i - 1][k] < x) {
        ad(id(i - 1, k), id(i, k));
      }
    }
    if (k) {
      if (a[i][k - 1] > x) {
        ad(id(i, k), id(i, k - 1));
      } else if (a[i][k - 1] < x) {
        ad(id(i, k - 1), id(i, k));
      }
    }
  }
  
  vc<int> q;
  FOR(i, N * M) if (in[i] == 0) q.ep(i);
  FOR(i, si(q)) {
    int n = q[i];
    for (int x : g[n]) {
      if (--in[x] == 0) q.ep(x);
    }
  }
  vc<char> vis(N * M);
  FOR_R(i, si(q)) {
    int n = q[i];
    bool ok = 0;
    for (int x : g[n]) ok |= not vis[x];
    vis[n] = ok;
  }
  INT(Q);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    print(vis[id(a, b)] ? "First" : "Second");
  }
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}