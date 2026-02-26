#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  VEC(int,a , 4);
  ll ans = inf<int>;
  Z g = [&](int e, int a, int b, int c) {
    ll s = inf<int>;
    FOR(i, 100) FOR(k, 100) {
      if (i * b + k * c > e) break;
      if ((e - i * b - k * c) % a == 0) {
        chmin(s, i + k + (e - i * b - k * c) / a);
      }
    }  
    return s;
  };
  Z f = [&](int x, int y, int z) {
    ll s = 0;
    for (int e : a) s += g(e, x, y, z);
    return s;
  };
  FOR(i, 1, 101) FOR(k, i + 1, 101) FOR(j, k + 1, 101) chmin(ans, f(i, k, j));
  print(ans);
}
#include "YRS/aa/main.hpp"