#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  vector<vector<PII>> v(N);
  vector<int> e;
  FOR(i, M) {
    INT(l, r, t, c);
    e.ep(c);
    --l;
    FOR(k, l, r) {
      v[k].ep(t, i);
    }
  }
  int ans = 0;
  FOR(i, N) {
    if (v[i].empty()) continue;
    sort(v[i]);
    ans += e[v[i][0].SE];
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"