#include "YRS/all.hpp"
#include "YRS/nt/seaweed_doubling.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  VEC(int, b, n);
  FOR(i, n) --a[i];
  FOR(i, n) --b[i];
  vc<int> res = subunit_monge_dmul(a, b);
  FOR(i, n) ++res[i];
  print(res);
}