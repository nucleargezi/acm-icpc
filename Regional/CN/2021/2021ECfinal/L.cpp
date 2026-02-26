#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  STR(s);
  vc<int> a(all(s));
  FOR(i, N) a[i] -= '0';
  vc<int> c(N);
  Z add = [&](int k) {
    ++k;
    k += k & -k;
    if (k <= N) c[k - 1] += 1;
  };
  FOR(i, N) if (a[i]) add(i);
  int r = 0;
  FOR(i, N) r += a[i] + c[i] == 1;
  print(r);
}
#include "YRS/aa/main.hpp"