#include "YRS/all.hpp"
#include "YRS/pr/crt.hpp"

void Yorisou() {
  INT(N, K);
  vc<int> I(N);
  iota(all(I), 0);
  FOR(K) {
    INT(x, y);
    --x, --y;
    swap(I[x], I[y]);
  }

  vc<u8> vis(N);
  vc<vc<int>> c;
  FOR(i, N) if (not vis[i]) {
    vc<int> cc;
    int t = i;
    while (not vis[t]) {
      vis[t] = 1;
      cc.ep(t);
      t = I[t];
    }
    c.ep(cc);
  }

  INT(Q);
  FOR(Q) {
    VEC(int, a, N);
    for (int &x : a) --x;
    bool ok = 1;
    vc<ll> as, ms;
    for (vc<int> &c : c) if (ok) {
      int sz = len(c);
      if (sz == 1) {
        int x = c[0];
        if (a[x] != x) ok = 0;
        continue;
      }
      int sh = -1, x = c[0];
      FOR(i, sz) {
        if (c[i] == a[x]) {
          sh = i;
          break;
        }
      }
      if (sh == -1) ok = 0;
      FOR(i, sz) {
        int x = c[i], w = c[(i + sh) % sz];
        if (a[x] != w) ok = 0;
      }
      as.ep(sh);
      ms.ep(sz);
    }
    if (not ok) print(-1);
    else {
      Z s = crt_reduce(as, ms);
      if (s == 0) {
        s = 1;
        for (ll x : ms) s = lcm((ll)s, x);
      }
      print(s);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"