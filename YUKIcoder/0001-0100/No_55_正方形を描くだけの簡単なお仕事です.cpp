#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
ll dist(ll x, ll y, ll xx, ll yy) {
  x -= xx, y -= yy;
  return x * x + y * y;
}
void Yorisou() {
  int x[3], y[3];
  FOR(i, 3) IN(x[i], y[i]);
  FOR(i, 3) FOR(k, i + 1, 3) {
    int X = x[i] + x[k], Y = y[i] + y[k];
    FOR(j, 3) if (j != i and j != k) {
      int tx = X - x[j], ty = Y - y[j];
      if (dist(x[j], y[j], x[i], y[i]) == dist(x[j], y[j], x[k], y[k]) and
          dist(x[i], y[i], x[k], y[k]) == dist(x[j], y[j], tx, ty)) {
        return print(tx, ty);
      }
    }
  }
  print(-1);
}
#include "YRS/aa/main.hpp"