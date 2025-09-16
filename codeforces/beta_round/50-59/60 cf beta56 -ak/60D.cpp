#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/dsu.hpp"
#include "YRS/math/nt/enumerate_pytagorean_triple.hpp"

// #define tests
void Yorisou() {
  INT(n);
  VEC(int, a, n);
  const int N = QMAX(a);
  vector<u8> vis(N + 1);
  for (int x : a) vis[x] = 1;
  dsu g(N + 1);
  enumerate_pytagorean_triple<true>(N << 1, [&](int a, int b, int c) -> void {
    for (int x : {a, b, c}) if (x <= N)
      for (int y : {a, b, c}) if (y <= N)
        if (x != y and vis[x] and vis[y]) {
          g.merge(x, y);
        }
  });
  int ans = 0;
  for (int x : a) if (g[x] == x) ++ans;
  UL(ans);
}
#include "YRS/Z_H/main.hpp"