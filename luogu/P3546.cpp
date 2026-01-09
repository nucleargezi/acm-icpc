#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/hash.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  STR(s);
  hash h(s);
  int ans = 0, sz = 0;
  FOR_R(i, N / 2 + 1) {
    sz = min(sz + 2, N / 2 - i);
    while (sz and h.get(i, i + sz) != h.get(N - i - sz, N - i)) --sz;
    if (h.get(0, i) == h.get(N - i, N)) chmax(ans, i + sz);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"