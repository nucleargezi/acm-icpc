#include "YRS/all.hpp"

void Yorisou() {
  using re = ld;
  INT(N, M);
  vc<vc<pair<int, re>>> g(N);
  FOR(M) {
    INT(x, y, w);
    g[y].ep(x, re(w) / 100);
  }
  re rs = 0;
  FOR(s, 1 << N) if ((s & 1) and (s >> (N - 1) & 1)) {
    re p = 1;
    FOR(n, 1, N) {
      re fl = 1;
      for (var [f, w] : g[n]) {
        if (s >> f & 1) fl *= (1 - w);
      }
      if (s >> n & 1) p *= (1 - fl);
      else p *= fl;
    }
    rs += p;
  }
  setp(10);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}