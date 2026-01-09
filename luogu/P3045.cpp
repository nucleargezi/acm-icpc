#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(N, K, V);
  int s = 0;
  min_heap<ll> d;
  min_heap<PII> in, ou;
  vc<int> c(N);
  FOR(i, N) {
    INT(x, y);
    in.eb(x, i);
    ou.eb(y, i);
    c[i] = x - y;
  }
  FOR(K) d.eb(0);
  vc<u8> vis(N);
  while (not in.empty() and V >= 0) {
    Z [x, i] = in.top();
    Z [y, k] = ou.top();
    if (vis[i]) {
      in.pop();
      continue;
    }
    if (vis[k]) {
      ou.pop();
      continue;
    }
    if (d.top() + y > x) {
      V -= x;
      in.pop();
      vis[i] = 1;
    } else {
      V -= y + d.top();
      d.pop();
      ou.pop();
      vis[k] = 1;
      d.eb(c[k]);
    }
    if (V >= 0) ++s;
  }
  print(s);
}
#include "YRS/aa/main.hpp"