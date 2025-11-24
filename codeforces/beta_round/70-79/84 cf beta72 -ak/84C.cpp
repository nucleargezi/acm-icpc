#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
ll dist(ll x, ll y, ll xx) { return x -= xx, x * x + y * y; }
void Yorisou() {
  INT(N);
  VEC(PII, r, N);
  const vector<int> I = argsort(r);
  vector<int> ans(N, -1);
  INT(Q);
  int s = 0;
  FOR(i, Q) {
    INT(x, y);
    int id = bina([&](int i) -> bool {
      if (i == N) return 1;
      return r[I[i]].fi >= x;
    }, N, -1);
    FOR(2) {
      if (id < N and id > -1) {
        Z [xr, rr] = r[I[id]];
        if (dist(x, y, xr) <= 1ll * rr * rr and ans[I[id]] == -1)
          ans[I[id]] = i + 1, ++s;
      }
      --id;
    }
  }
  print(s);
  print(ans);
}
#include "YRS/Z_H/main.hpp"