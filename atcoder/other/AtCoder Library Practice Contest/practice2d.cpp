#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_v.hpp"

void Yorisou() {
  INT(N, M);
  VEC(string, s, N);
  
  vc<vc<int>> g(N * M);
  Z id = [&](int x, int y) { return x * M + y; };
  Z sp = [&](int x) { return PII{x / M, x % M}; };
  Z ad = [&](int i, int k) { g[i].ep(k), g[k].ep(i); };

  FOR(i, N) FOR(k, M) if (s[i][k] == '.') {
    if (i and s[i - 1][k] == '.') ad(id(i, k), id(i - 1, k));
    if (k and s[i][k - 1] == '.') ad(id(i, k), id(i, k - 1));
  }
  
  Z mat = BM_v(g)();
  for (Z [a, b] : mat) {
    Z [x, y] = sp(a);
    Z [xx, yy] = sp(b);
    if (x > xx) swap(x, xx), swap(y, yy);
    if (y > yy) swap(x, xx), swap(y, yy);
    if (x < xx) s[x][y] = 'v', s[xx][yy] = '^';
    else s[x][y] = '>', s[xx][yy] = '<';
  }

  print(si(mat));
  FOR(i, N) print(s[i]);
}

int main() {
  Yorisou();
  return 0;
}