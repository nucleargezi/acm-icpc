#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/steiner.hpp"

void Yorisou() {
  INT(N, M, K);
  VEC(int, a ,N * M);
  vc<int> p(K);
  FOR(i, K) {
    INT(a, b);
    --a, --b;
    p[i] = a * M + b;
  }

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

  vc<string> mp(N, string(M, '.'));
  for (int s : vs) {
    int x = s / M, y = s % M;
    mp[x][y] = 'X';
  }
  print(w);
  FOR(i, N) print(mp[i]);
}

int main() {
  Yorisou();
  return 0;
}