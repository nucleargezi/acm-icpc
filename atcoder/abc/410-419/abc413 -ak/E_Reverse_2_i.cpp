#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
void Yorisou() {
  LL(n);
  const int N = 1 << n;
  vector<vector<int>> v(N);
  VEC(int, p, N);
  FOR(i, N) v[i].emplace_back(p[i]);
  while (len(v) > 1) {
    vector<vector<int>> nv;
    FOR(i, 0, len(v), 2) {
      bool f = v[i] < v[i + 1];
      nv += v[i + not f] + v[i + f];
    }
    v.swap(nv);
  }
  UL(v[0]);
}
#include "MeIoN_Lib/Z_H/main.hpp"