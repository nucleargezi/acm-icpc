#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/nt/bigint/big.hpp"

#define tests 1
#define fl 0
#define DB 10
using G = bigint;
bool cp(const G &a, const G &b) {
  if (len(a.a) != len(b.a)) return len(a.a) > len(b.a);
  int sz = len(a.a) - 1;
  return a.a[sz] > b.a[sz];
}
void Yorisou() {
  int N, K;
  string str;
  IN(N, K, str);
  int B = N / (K + 1);
  G ans = str, t;
  for (int z : {-1, 0}) {
    vc<int> g;
    int U = 1;
    FOR(K) U *= 3;
    FOR(s, U) {
      g.clear();
      int xx = s, ss = 0;
      bool o = 1;
      FOR(K) {
        int x = xx % 3;
        xx /= 3;
        x = B + x + z;
        g.ep(x);
        ss += x;
      }
      g.ep(N - ss);
      FOR(i, 1, K + 1) if (abs(g[i] - g[i - 1]) > 1) o = 0;
      if (not o or QMIN(g) <= 0) continue;
      t = 0;
      int l = 0;
      FOR(i, K + 1) {
        int sz = g[i];
        t += G(str.substr(l, sz));
        if (cp(t, ans)) break;
        l += sz;
      }
      if (t < ans) ans = t;
    }
  }
  print(ans);
}
#include "YRS/aa/main.hpp"