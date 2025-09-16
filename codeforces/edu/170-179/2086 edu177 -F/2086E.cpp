#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"

#define tests
using T = vector<vector<ll>>;
void Yorisou() {
  LL(L, R, K);
  if (K > 100) return print(0);
  map<ll, T> mp;
  Z f = [&](Z &f, ll n) -> T {
    if (n == 0) return T(3, vector<ll>(K + 1));
    if (mp.contains(n)) return mp[n];
    T res(3, vector<ll>(K + 1));
    FOR(i, 1, 4) if (i <= n and i <= K) ++res[i % 3][i];
    FOR(i, 4) {
      if (n < i + 4) break;
      ll t = (n - i) >> 2;
      Z s = f(f, t);
      FOR(k, 3) FOR(j, K + 1 - i) res[(k + i) % 3][j + i] += s[k][j];
    }
    return mp[n] = res;
  };
  Z keis = [&](ll K) -> ll {
    return SUM(f(f, R * 3 + K)[K % 3]) - 
           SUM(f(f, L * 3 + K - 1)[K % 3]);
  };
  print(keis(K) - keis(K - 1));
}
#include "YRS/Z_H/main.hpp"