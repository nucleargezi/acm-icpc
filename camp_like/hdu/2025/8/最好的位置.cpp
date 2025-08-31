#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Tree/Basic.hpp"

#define tests
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vector<int> to(N);
  for (int i = 0; i < N; ++i) {
    to[a[i]] = i;
  }
  graph g(N);
  g.read_tree();

  tree v(g);
  int meter = 0, l = to[0], r = to[0];
  for (int i = 0; i < N; ++i) {
    int nl = l, nr = r;
    int nxt = meter;
    if (chmax(nxt, v.dist(l, to[i]))) {
      nl = l, nr = to[i];
    }
    if (chmax(nxt, v.dist(to[i], r))) {
      nl = to[i], nr = r;
    }
    std::tie(l, r, meter) = T3<int>{nl, nr, nxt};
    UL((meter + 1) >> 1);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"