#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/seq/inversion.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  FOR(i, N) --a[i];
  bool o = inversion(a) & 1;
  int x = 0, y = 0;
  FOR(i, N) x += i == a[i];
  FOR(i, N) y += ~(i + a[i]) & 1;
  FOR(Q) {
    INT(e, r);
    o = not o;
    --e, --r;
    x -= a[e] == e;
    x -= a[r] == r;
    y -= ~(a[e] + e) & 1;
    y -= ~(a[r] + r) & 1;
    swap(a[e], a[r]);
    x += a[e] == e;
    x += a[r] == r;
    y += ~(a[e] + e) & 1;
    y += ~(a[r] + r) & 1;
    if (x == N) print(-1);
    else if (o) print(N);
    else if (y < N) print(N - 1);
    else print(N - 2);
  }
}
#include "YRS/aa/main.hpp"