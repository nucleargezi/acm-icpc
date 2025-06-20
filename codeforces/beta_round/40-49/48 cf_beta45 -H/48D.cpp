#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  constexpr int N = 1'000'00;
  vector<vector<int>> v(N);
  FOR(i, n) v[--a[i]] += i;
  FOR(i, N - 1) if (len(v[i + 1]) > len(v[i])) iroha UL(-1);
  vector<int> ans(n);
  FOR(i, N) for (int t = 0; int id : v[i]) ans[id] = ++t;
  UL(len(v[0]));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"