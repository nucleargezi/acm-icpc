#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
using bs = bitset<4000>;
void Yorisou() {
  LL(n, m);
  vector<bs> a(n);
  FOR(i, n) {
    S(s);
    FOR(k, m) a[i][k] = s[k] == '1';
  }
  LL(q);
  FOR(q) {
    LL(i, k, l, r, p);
  }
  FOR(i, n - 1) a[i + 1] &= a[i];
  UL(a[--n].count());
}
#include "MeIoN_Lib/Z_H/main.hpp"