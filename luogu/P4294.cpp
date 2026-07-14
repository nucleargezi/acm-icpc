#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/steiner.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a ,N * M);
  vc<int> p;
  FOR(i, N * M) if (a[i] == 0) p.ep(i);
  vc<string> mp(N, string(M, '_'));

  if (si(p)) {
    vc<vc<edge_id_w<int>>> g(N * M);
    Z id = [&](int a, int b) { return a * M + b; };
    int m = 0;
    Z ae = [&](int a, int b) {
      g[a].ep(b, m, 0);
      g[b].ep(a, m, 0);
      ++m;
    };  
    FOR(i, N) FOR(k, M) {
      if (i) ae(id(i - 1, k), id(i, k));
      if (k) ae(id(i, k - 1), id(i, k));
    }
    Z [w, vs, es] = steiner(g, p, a);
    for (int s : vs) {
      int x = s / M, y = s % M;
      mp[x][y] = 'o';
    }
    for (int s : p) {
      int x = s / M, y = s % M;
      mp[x][y] = 'x';
    }
    print(w);
  } else {
    print(0);
  }

  FOR(i, N) print(mp[i]);
}

int main() {
  Yorisou();
  return 0;
}