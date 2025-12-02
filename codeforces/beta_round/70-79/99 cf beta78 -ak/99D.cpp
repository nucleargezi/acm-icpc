#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/bigint/big.hpp"

#define tests 0
#define fl 0
#define DB 10
using B = bigint;
struct F {
  B u, d;
  F(B x = 0, B y = 1) : u(x), d(y) { bina(); }
  void out() { print(u.to_string() + "/" + d.to_string()); }
  void bina() {
    B g = u.gcd(d);
    if (not g.is_one()) u /= g, d /= g;
  }
};
F add(F a, F b) { return F(a.u * b.d + a.d * b.u, a.d * b.d); }
F mul(F a, F b) { return F(a.u * b.u, a.d * b.d); }
void Yorisou() {
  LL(N);
  int c = 0;
  while (~N & 1) N >>= 1, ++c;
  if (N == 1) return F(c, 1).out();
  vector<ll> A;
  ll x = 1;
  while (1) {
    x <<= 1;
    A.ep(x / N);
    x %= N;
    if (x == 1) break;
  }
  int sz = len(A);
  reverse(A);
  B a = 0, b = 0, bs = 1;
  FOR(i, sz) {
    a += bs * A[i];
    b += bs * ((sz - i) * A[i]);
    bs *= 2;
  }
  F X = F(a * sz, (bs - 1).pow(2)), Y = F(b, bs - 1);
  add(mul(add(X, Y), F(N)), F(c, 1)).out();
}
#include "YRS/Z_H/main.hpp"