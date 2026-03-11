#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(k, j, N);
  if (k > j) swap(k, j);
  Z f = [&](int s) -> int {
    vc<u8> g(N + 1);
    int r = 1;
    g[s] = 1;
    s += j;
    while (s <= N) {
      g[s] = 1;
      ++r;
      s += j;
    }
    int rs = s - N - 1, st = 0;
    s = k;
    while (s <= N) {
      if (s + st <= N and g[s + st]) {
        if (rs) --rs, ++st;
        else --s;
      }
      ++r;
      s += k;
    }
    return r;
  };
  int s = inf<int>;
  FOR(i, max(1, j - 100), j + 1) chmin(s, f(i));
  swap(j, k);
  FOR(i, max(1, j - 100), j + 1) chmin(s, f(i));
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"