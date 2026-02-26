#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, D, K);
  vc<ll> s(K);
  int ls = 0;
  FOR(i, K) {
    FOR(k, ls + 1, N + 1) {
      ll l = k, r = k;
      FOR(j, i + 1, K) l += j - i + k;
      FOR(j, i + 1, K) r += N - (K - j - 1);
      if (l <= D and D <= r) {
        ls = s[i] = k;
        D -= k;
        break;
      }
    }
  }
  if (QMIN(s) == 0) return print(-1);
  print(s);
}
#include "YRS/aa/main.hpp"