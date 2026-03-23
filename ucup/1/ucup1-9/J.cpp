#include "YRS/all.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  if (N == M) return print("Richman");
  int c = count(all(a), 0);
  M -= c;
  if (M < 0) return Impossible();
  vc<int> b;
  FOR(i, N) if (a[i] != 0) b.ep(a[i]);
  a.swap(b);
  N = si(a);
  ll s = accumulate(bg(a), bg(a) + M, 0ll);
  int mn = inf<int>;
  FOR(i, M, N) chmin(mn, a[i]);
  print(s + mn - 1);
}
constexpr int tests = 1, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"