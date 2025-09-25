#include "YRS/all.hpp"
#include "YRS/debug.hpp"

// #define tests
int N, M;
void yorisou() {
  VEC(string, a, N);
  for (Z &s : a) for (Z &c : s) c -= '0';
  int c = 0;
  int l = M, r = -1, u = N, d = -1;
  FOR(i, N) FOR(k, M) if (a[i][k]) {
    chmin(l, k);
    chmax(r, k);
    chmin(u, i);
    chmax(d, i);
    ++c;
  }
  Yes(c == (r - l + 1) * (d - u + 1));
}
void Yorisou() {
  while (IN(N, M)) yorisou();
}
#include "YRS/Z_H/main.hpp"