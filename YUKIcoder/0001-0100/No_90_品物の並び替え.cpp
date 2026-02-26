#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(T3<int>, e, M);
  vc<int> I(N);
  iota(all(I), 0);
  ll ans = 0;
  do {
    ll s = 0;
    for (Z &&[f, t, w] : e) {
      if (I[f] < I[t]) s += w;
    }
    chmax(ans, s);
  } while (next_permutation(all(I)));
  print(ans);
}
#include "YRS/aa/main.hpp"