#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"
#include "MeIoN_Lib/graph/Apck/Basic.hpp"
#include "MeIoN_Lib/graph/Apck/euler_walk.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(PII, a, n);

  vector<int> u;
  FOR(i, n) u += a[i].first;
  unique(u);
  const int B = len(u);
  FOR(i, n) a[i].first = lower_bound(u, a[i].first);

  u.clear();
  FOR(i, n) u += a[i].second;
  unique(u);
  const int N = len(u);
  FOR(i, n) a[i].second = lower_bound(u, a[i].second);

  graph g(B + N);
  FOR(i, n) g.add(a[i].first, a[i].second + B);
  g.build();
  meion ans = euler_walk(g).second;
  if (ans.empty()) iroha NO();
  YES();
  for (int &x : ans) ++x;
  print("{}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"