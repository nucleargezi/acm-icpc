#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/poly/fft_convolution.hpp"

#define tests 0
#define fl 0
#define DB 10
using RE = double;
void Yorisou() {
  INT(N);
  VEC(RE, f, N);
  f.insert(f.begin(), 0);
  vc<RE> g(N + 1);
  FOR(i, 1, N + 1) g[i] = RE(1) / i / i;
  Z x = fft_convolution(f, g);
  reverse(f);
  Z y = fft_convolution(f, g);
  setp(3);
  FOR(i, N) print(x[i + 1] - y[N - i - 1]);
}
#include "YRS/Z_H/main.hpp"