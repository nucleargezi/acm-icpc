#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/Basic.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc(M);
  if (N == 1) return YES();
  if (N == 2) return YES();
  if (N == 3) return YES();
  vc<int> in = g.deg();
  sort(in);
  if (N == 4 and QMIN(in) == QMAX(in)) return YES();
  if (QMIN(in) == N - 1) return YES();
  if (in[N - 2] == 1 and in[N - 1] == N - 1) return YES();
  if (in[0] == 0 and in[1] == N - 2) return YES();
  NO();
}
#include "YRS/aa/main.hpp"