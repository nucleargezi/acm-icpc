#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, d, N);
  VEC(int, w, N);
  dsu g(N);
  vc<int> st;
  vc<u8> ok(N);
  FOR(i, N) {
    int x = (i + d[i]) % N;
    int y = ((i - d[i]) % N + N) % N;
    g.merge(x, y);
    if (x == y) st.ep(x);
  }
  for (int x : st) ok[g[x]] = 1;
  vc<int> c(N);
  FOR(i, N) c[g[i]] += w[i] == 0;
  FOR(i, N) if (g[i] == i and ((c[i] & 1) and not ok[i])) return No();
  Yes(); 
}
#include "YRS/aa/main.hpp"