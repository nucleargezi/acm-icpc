#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/others/date_time.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  using T = datetime;
  LL(N);
  T x(2014, 7, 23);
  int w = x.wk();
  vc<u8> dat;
  FOR(i, 400) dat.ep(T(2015 + i, 7, 23).wk() == w);
  ll s = SUM<ll>(dat) * ((N - 2014) / 400);
  N = (N - 2014) % 400;
  FOR(i, N) s += dat[i];
  print(s);
}
#include "YRS/aa/main.hpp"