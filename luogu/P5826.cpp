#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(_, n, q, m);
  vector<int> v[m];
  VEC(int, a, n);
  FOR(i, n) v[--a[i]] += i;
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
    Yes(ok);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"