#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, a, b);
  --a, --b;
  vc<vc<int>> g(N);
  FOR(i, 1, N) g[i - 1].ep(i), g[i].ep(i - 1);
  g[a].ep(b), g[b].ep(a);
  vc<int> dis(N), q(N), s(N - 1);
  FOR(i, N) {
    fill(all(dis), N);
    int l = 0, r = 0;
    q[r++] = i, dis[i] = 0;
    while (l < r) {
      int n = q[l++];
      for (int x : g[n]) if (chmin(dis[x], dis[n] + 1)) q[r++] = x;
    }
    FOR(k, N) if (i != k) ++s[dis[k] - 1];
  }
  for (int x : s) print(x / 2);
}

int main() { Yorisou(); }