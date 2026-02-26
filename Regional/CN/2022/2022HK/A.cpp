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
  vc<vc<int>> v(N);
  FOR(i, N) {
    INT(f);
    --f;
    if (f != -1) v[f].ep(i);
  }
  Z f = [&](Z &f, int n) -> int {
    max_heap<int> q;
    for (int x : v[n]) q.eb(f(f, x));
    if (q.empty()) return 1;
    int s = pop(q);
    if (not q.empty()) chmax(s, pop(q) + 1);
    return s;
  };
  print(f(f, 0));
}
#include "YRS/aa/main.hpp"