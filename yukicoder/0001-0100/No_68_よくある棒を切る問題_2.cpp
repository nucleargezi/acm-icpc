#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N);
  max_heap<pair<re, int>> q;
  FOR(N) {
    INT(x);
    q.eb(x, 1);
  }
  vc<re> ans(5'000'00 + 1);
  ans[0] = q.top().fi;
  FOR(i, 1, 5'000'00 + 1) {
    Z [x, c] = pop(q);
    ans[i] = x;
    q.eb(x * c / (c + 1), c + 1);
  }
  INT(Q);
  setp(10);
  FOR(Q) {
    INT(x);
    print(ans[x]);
  }
}
#include "YRS/aa/main.hpp"