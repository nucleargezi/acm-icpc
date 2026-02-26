#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/Basic.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  tree v(g);
  vc<int> in = g.deg_array(), sz = v.subtree_size_arr();
  in[0] = 0;
  FOR(i, 1, N) in[i] = in[i] == 1;
  int s = SUM(in);
  vc<int> c(N + 1);
  c[1] = s;
  vc<u8> vis(N + 1);
  for (int x : argsort(sz)) {
    int t = sz[x];
    if (c[t] == s) vis[t] = 1;
    c[t] -= in[x];
    int f = v.fa[x];
    if (f != -1) c[sz[f]] += in[x], in[f] += in[x];
  }
  vc<int> ans;
  FOR(i, 1, N + 1) if (vis[i]) ans.ep(i);
  print(len(ans));
  print(ans);
}
#include "YRS/aa/main.hpp"