#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/queue.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, V);
  vvc<int> v(N + 2);
  vc<int> a(N + 2, -1);
  FOR(N) {
    INT(x, y, z, w);
    a[x] = w;
    v[y].ep(x);
    v[z].ep(x);
  }
  vc<ll> f(N + 2);
  vc<u8> vis(N + 2);
  FOR(i, 2, N + 2) if (a[i] != -1) {
    ll s = 0;
    queue<int> q;
    q.eb(i);
    vis[i] = 1;
    while (not q.empty()) {
      int n = q.pop();
      if (a[n] != -1) s += a[n];
      for (int x : v[n]) if (not vis[x]) {
        vis[x] = 1;
        q.eb(x);
      }
    }
    f[i] = s;
    fill(all(vis), 0);
  }
  int s = 0;
  FOR(i, 2, N + 2) if (a[i] != -1) if (f[i] >= V) print(i, f[i]), ++s;
  print(s);
}
#include "YRS/aa/main.hpp"