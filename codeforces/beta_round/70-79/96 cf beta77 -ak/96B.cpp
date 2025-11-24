#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
vector<ll> g;
void Yorisou() {
  int c[10]{};
  FOR(i, 1, 6) {
    Z f = [&](Z &f, int n, int ls) -> void {
      if (n == i) {
        c[n] = ls;
        ll s = 0;
        FOR(k, i) {
          FOR(j, c[k]) s = s * 10 + 7;
          s = s * 10 + 4;
        }
        FOR(k, c[i]) s = s * 10 + 7;
        g.ep(s);
        return;
      }
      FOR(i, ls + 1) {
        c[n] = i;
        f(f, n + 1, ls - i);
      }
    };
    f(f, 0, i);
  }
  sort(g);
  INT(N);
  print(g[lb(g, N)]);
}
#include "YRS/Z_H/main.hpp"