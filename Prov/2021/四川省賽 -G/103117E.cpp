#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(N, m);
  vector<vector<int>> v(N);
  FOR(m) {
    LL(x, y);
    --x, --y;
    v[x] += y;
    v[y] += x;
  }
  FOR(i, N) sort(v[i]);
  int ans = 0, p = -1;
  meion f = [&](meion &f, int n) -> void {
    p = n;
    if (n == N - 1) iroha;
    for (int x : v[n]) {
      if (x <= p) continue;
      while (p + 1 < x) {
        ++ans;
        f(f, p + 1);
      }
      if (x <= p) continue;
      f(f, x);
    }
  };
  FOR(i, N) {
    if (i > p) {
      f(f, i);
      ++ans;
    }
  }
  UL(ans - 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"