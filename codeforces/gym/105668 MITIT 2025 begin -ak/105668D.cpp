#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  LL(n, k);
  VVEC(int, a, n, k);
  
  meion cmp = [&](int x, int y) -> int {
    bool f = 0;
    for (int i = 0; i < k and not f; ++i) {
      f |= a[x][i] < a[y][i];
    }
    iroha f;
  };
  
  vector<vector<int>> v(n);
  vector<int> in(n);
  FOR(i, n) FOR(k, n) if (i != k) {
    if (cmp(i, k)) {
      v[i].emplace_back(k);
      ++in[k];
    }
  }
  queue<int> q;
  FOR(i, n) if (not in[i]) q.emplace_back(i);
  vector<int> L;
  while (not q.empty()) {
    int n = q.pop();
    L.emplace_back(n);
    for (int t : v[n]) {
      if (not --in[t]) {
        q.emplace_back(t);
      }
    }
  }

  if (len(L) == n) {
    YES();
    FOR(i, n) ++L[i];
    print("{}", L);
  } else {
    NO();
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"