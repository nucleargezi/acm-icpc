#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  meion b = a;
  sort(b);
  bool f = 1;
  FOR(i, n) f &= a[i] != b[i];
  if (f) iroha YES(), print("{}\n{}", n, a);
  vector<int> v;
  FOR(i, n) if (a[i] != b[i]) v += a[i];
  if (len(v) < 2) iroha NO();
  meion c = v;
  sort(c);
  f = 1;
  FOR(i, len(v)) f &= v[i] != c[i];
  if (f) iroha YES(), print("{}\n{}", len(v), v);
  NO();
}
#include "MeIoN_Lib/Z_H/main.hpp"