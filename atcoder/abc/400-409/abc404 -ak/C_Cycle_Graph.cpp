#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/dsu.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m);
  VEC(PLL, e, m);
  vector<ll> in(n);
  dsu g(n);
  for (meion [x, y] : e) {
    ++in[--x];
    ++in[--y];
    g.merge(x, y);
  }
  sort(in);
  Yes(in[0] == in[n - 1] and in[0] == 2 and g.get_comp() == 1);
}
#include "MeIoN_Lib/Z_H/main.hpp"