#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  I128(N, M);
  vc<int> f;
  FOR(1000) {
    int x = N / M;
    vc<int> g;
    while (x) g.ep(x % 10), x /= 10;
    reverse(g);
    f.insert(f.end(), all(g));
    N %= M;
    N *= 10;
  }
  if (N != 0) {
    print(-1);
  } else {
    while (not f.empty() and f.back() == 0) pop(f);
    print(f.back());
  }
}
#include "YRS/aa/main.hpp"