#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/hash.hpp"
#include "YRS/ds/fenw/fenw01.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  const int N = len(s);
  hash h(s);
  INT(t);
  vector<int> sz;
  vector bit(t, fenw01(N));
  vector<hash> ht;
  FOR(i, t) {
    STR(t);
    const int M = len(t);
    sz.ep(M);
    ht.ep(hash(t));
  }
  int ans = 0, p = 0;
  FOR_R(l, N) {
    FOR(i, t) if (l + sz[i] <= N and h.get(l, l + sz[i]) == ht[i].get_all())
      bit[i].add(l + sz[i] - 1);
    int r = bina([&](int r) -> bool {
      bool f = 1;
      FOR(i, t) f &= not bit[i].prod(l, r);
      return f;
    }, l, N + 1);
    if (chmax(ans, r - l)) p = l;
  }
  print(ans, p);
}
#include "YRS/Z_H/main.hpp"