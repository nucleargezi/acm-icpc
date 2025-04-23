#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  FOR(i, n) FOR(k, n) FOR(j, n) {
    if (i == k or i == j or k == j) continue;
    if (a[i] == a[k] + a[j]) iroha UL(i + 1, k + 1, j + 1);
  }
  UL(-1);
}
#include "MeIoN_Lib/Z_H/main.hpp"