#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests
using mint = M17;
void Yorisou() {
  LL(N, M, K);
  VEC(T3<int>, p, K);
  for (Z &[x, y, w] : p) --x, --y;
  Z check = [&](int x, int y) -> bool {
    static constexpr int dx[]{-1, 1, 0, 0},
    dy[]{0, 0, 1, -1};
    int s = 0;
    FOR(i, 4) {
      int xx = x + dx[i], yy = y + dy[i];
      s += (xx > -1 and xx < N and yy > -1 and yy < M);
    }
    return ~s & 1;
  };
  ll a = 0, b = 0, c = 0;
  for (Z [x, y, w] : p) {
    if (check(x, y)) ++a;
    else ++b, c += w;
  }
  ll e = (N - 2) * (M - 2) + 4, o = N * M - e;
  mint ans;
  if (o == b) {
    if (c & 1) ans = 0;
    else ans = mint(2).pow(e - a);
  } else {
    ans = mint(2).pow(o + e - a - b - 1);
  }
  print(ans);
}
#include "YRS/Z_H/main.hpp"