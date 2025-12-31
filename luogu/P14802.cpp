#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/basic/hull.hpp"

#define tests 1
#define fl 0
#define DB 10000
using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  vc<int> h = hull<ll, 1>(a);
  
  ll s = 0;
  int sz = len(h);
  FOR(i, sz) {
    int k = (i + 1) % sz;
    s += a[h[i]].det(a[h[k]]);
  }
  s = std::abs(s);

  vc<u8> vis(N, 1);
  for (int x : h) vis[x] = 0;
  vc<P> lst;
  FOR(i, N) if (vis[i]) lst.ep(a[i]);
  vc<int> nh = hull<ll, 1>(lst);

  int p = 0, m = len(nh);
  ll mx = inf<ll>;
  Z f = [&](int i, int k, int j) -> ll {
    P x = a[h[i]], y = a[h[k]], z = lst[nh[j]];
    return std::abs((y - x).det(z - x));
  };
  if (not m) {
    mx = s + 1;
  } else {
    bool st = 1;
    FOR(i, sz) {
      int k = (i + 1) % sz;
      if (st) {
        st = 0;
        ll mx = inf<ll>;
        FOR(j, m) if (chmin(mx, f(i, k, j))) p = j;
      }
      int t = 0;
      while (1) {
        int nx = (p + 1) % m;
        if (t < m and nx != p and f(i, k, nx) <= f(i, k, p)) {
          p = nx, ++t;
        } else {
          break;
        }
      }
      chmin(mx, f(i, k, p));
    }
  }
  print(s - mx);
}
#include "YRS/aa/main.hpp"