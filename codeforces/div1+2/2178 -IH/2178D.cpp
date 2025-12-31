#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  vc<int> I = argsort(a);
  vc<PII> ans;
  if (N == M or M + M > N) return print(-1);
  if (M == 0) {
    if (N < 3 or 2ll * QMAX(a) > SUM<ll>(a)) return print(-1);
    int id = 0;
    ll s = 0;
    while (s < a[I[N - 1]] - a[I[N - 2]]) {
      ans.ep(I[id], I[N - 1]);
      s += a[I[id]];
      ++id;
    }
    if (id < N - 2) {
      s = a[I[id]];
      FOR(k, id + 1, N - 2) {
        if (s > a[I[k]]) {
          ans.ep(I[k], I[id]);
          s -= a[I[k]];
        } else {
          ans.ep(I[id], I[k]);
          s = a[I[k]] - s;
          id = k;
        }
      }
      ans.ep(I[id], I[N - 2]);
    }
    ans.ep(I[N - 2], I[N - 1]);
  } else {
    int id = 0, ls = a[I[0]];
    FOR(i, 1, N - 2 * M + 1) {
      if (ls > a[I[i]]) {
        ans.ep(I[i], I[id]);
        ls -= a[I[i]];
      } else {
        ans.ep(I[id], I[i]);
        ls = a[I[i]] - ls;
        id = i;
      }
    }
    vc<int> rs{I[id]};
    FOR(i, N - 2 * M + 1, N - M) rs.ep(I[i]);
    FOR(i, M) ans.ep(I[N - M + i], rs[i]);
  }
  print(len(ans));
  for (Z [x, y] : ans) print(x + 1, y + 1);
}
#include "YRS/aa/main.hpp"