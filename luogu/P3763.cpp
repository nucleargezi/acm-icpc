#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/string_cmp.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  STR(s, t);
  int N = len(s), M = len(t);
  s += t;
  string_cmp sa(s);
  int ans = 0;
  FOR(i, N - M + 1) {
    int p = i, pp = 0, s = sa.getlcp(p, pp + N);
    p += s, pp += s;
    FOR(3) {
      if (pp >= M) break;
      ++p, ++pp;
      if (pp >= M) break;
      s = sa.getlcp(p, pp + N);
      p += s, pp += s;
    }
    ans += pp >= M;
  }
  print(ans);
}
#include "YRS/aa/main.hpp"