#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<1'000'000'000 + 9>;
struct ds {
  vector<int> fa;
  ds(int N) : fa(N, -1) {}
  int f(int x) {
    while (fa[x] >= 0) {
      int p = fa[fa[x]];
      if (p < 0) return fa[x];
      x = fa[x] = p;
    }
    return x;
  }
  bool me(int x, int y) {
    x = f(x), y = f(y);
    if (x == y) return 0;
    if (fa[x] > fa[y]) swap(x, y);
    fa[x] += fa[y], fa[y] = x;
    return 1;
  }
};
void Yorisou() {
  INT(N, M);
  ds g(N);
  mint s = 0;
  FOR(M) {
    INT(x, y);
    --x, --y;
    if (not g.me(x, y)) s = s * 2 + 1;
    print(s);
  }
}
#include "YRS/Z_H/main.hpp"