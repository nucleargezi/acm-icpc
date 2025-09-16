#include "YRS/Z_H/MeioN.hpp"
#include "YRS/Z_H/MeIoN_H.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/basic/queue.hpp"

// #define tests
void Yorisou() {
  INT(N, M);
  vector<vector<int>> v(N);
  vector<int> in(N);
  FOR(M) {
    INT(x, y);
    --x, --y;
    v[x].emplace_back(y);
    ++in[y];
  }
  queue<int> q;
  FOR(i, N) if (not in[i]) q.emplace(i);
  while (not q.empty()) {
    int n = q.pop();
    if (not q.empty()) iroha No();
    for (int t : v[n]) {
      if (not --in[t]) q.emplace(t);
    }
  }
  Yes();
}
#include "YRS/Z_H/main.hpp"