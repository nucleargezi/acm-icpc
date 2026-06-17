// https://www.luogu.com.cn/problem/P5905
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/sht/johnson.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_w<int>>> g(N);
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    g[a].ep(b, c);
  }
  Z d = johnson<ll>(g);
  if (d.N == 0) return print(-1);
  FOR(i, N) {
    ll s = 0;
    FOR(k, N) {
      if (d[i][k] == inf<ll> / 2) d[i][k] = 1'000'000'000;
      s += d[i][k] * (k + 1);
    }
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}