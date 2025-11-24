#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/hashmap.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  vector<vector<PII>> v(N + 1);
  FOR(i, N + 1) {
    int s = 0;
    FOR(k, i, N + 1 - s) {
      s += k;
      if (k - i > 0) v[s].ep(i, k);
    }
  }
  vector<int> f(N + 1), g(f);
  FOR(i, 2, N) {
    hash_map<int> c;
    for (Z [x, y] : v[i]) c[g[y] ^ g[x - 1]]++;
    while (c[f[i]]) ++f[i];
    g[i] = g[i - 1] ^ f[i];
  }
  int ans = N + 1;
  for (Z [x, y] : v[N]) 
    if ((g[y] ^ g[x - 1]) == 0) chmin(ans, y - x + 1);
  print(ans == N + 1 ? -1 : ans);
}
#include "YRS/Z_H/main.hpp"