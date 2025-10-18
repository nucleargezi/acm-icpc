#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(int, a, n);
  ll m = QMAX(a);
  vector<int> v[1'000'000];
  FOR(i, n) v[--a[i]] += i;
  LL(q);
  FOR(q) {
    LL(n);
    VEC(int, a, n);
    int p = -1, ok = 1;
    FOR(i, n) {
      meion it = upper(v[--a[i]], p);
      if (it == v[a[i]].end()) {
        ok = 0;
        break;
      }
      p = *it;
    }
    UL(ok ? "TAK" : "NIE");
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"