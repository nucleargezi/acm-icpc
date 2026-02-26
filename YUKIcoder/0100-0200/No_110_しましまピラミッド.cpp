#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  INT(M);
  VEC(int, b, M);
  sort(a);
  sort(b);
  int ans = 0;
  FOR(2) {
    min_heap<int> qa, qb;
    for (int x : a) qa.eb(x);
    for (int x : b) qb.eb(x);
    int l = -inf<int>, s = 0;
    while (1) {
      while (not qa.empty() and qa.top() <= l) pop(qa);
      if (qa.empty()) break;
      ++s;
      l = pop(qa);
      qa.swap(qb);
    }
    chmax(ans, s);
    a.swap(b);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"