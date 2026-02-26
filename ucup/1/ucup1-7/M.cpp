#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  if (N & 1) N <<= 1, a.insert(a.end(), all(a));
  vc<u8> vis(N);
  vc<ll> ans(3);
  FOR(i, N) if (a[i] and not vis[i]) {
    int f = i;
    ll s = 0, o = 0, e = 0;
    while (not vis[f]) {
      int t = (f + a[f]) % N;
      o += f & 1;
      e += ~f & 1;
      s += a[f];
      vis[f] = 1;
      f = t;
    }
    s /= N;
    if (o and e) ans[2] += s;
    else if (e) ans[0] += s;
    else ans[1] += s;
  }
  print(ans);
}
#include "YRS/aa/main.hpp"