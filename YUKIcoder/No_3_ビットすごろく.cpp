#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/graph/Apck/bfs1.hpp"

// #define tests
void Yorisou() {
  LL(n);
  graph<int, 1> g(n + 1);
  FOR(i, 1, n + 1) {
    if (i - popcount(i) > 0) g.add(i, i - popcount(i));
    if (i + popcount(i) < n + 1) g.add(i, i + popcount(i));
  }
  g.build();
  int ans = bfs1(g, 1).first[n];
  UL(ans == inf<int> ? -1 : ans + 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"