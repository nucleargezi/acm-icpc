#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
#define print(...) print(__VA_ARGS__), cout.flush()
ll x;
ll q(int l, int r) { return print("?", l, r), IN(x), x; }
void R(ll x) { print("!", x); }
void Yorisou() {
  LL(N);
  int l = 1, r = N;
  ll s = q(l, r);
  if (N == 1) return R(s);
  for (; l < r; s >>= 1) {
    int k = bina([&](int m) { return q(l, m) <= (s >> 1); }, l, r);
    if (k + k < r + l) r = k;
    else l = k + 1;
  }
  R(s);
}
#include "YRS/aa/main.hpp"