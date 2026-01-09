#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/block_cut_tree.hpp"
#include "YRS/tr/Basic.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M);
  graph g(N);
  g.read_graph(M);
  Z bct = block_cut(g);
  tree v(bct);
  hash_map<int> mp(N);
  FOR(i, N, bct.N) {
    if (bct.deg(i) == 2) {
      vc<int> a;
      for (Z &&e : bct[i]) {
        a.ep(e.to);
      }
      if (a[0] > a[1]) swap(a[0], a[1]);
      mp[ull(a[0]) << 32 | a[1]] = i;
    }
  }
  INT(Q);
  FOR(Q) {
    INT(op);
    if (op == 1) {
      INT(x, y, a, b);
      --x, --y, --a, --b;
      if (a > b) swap(a, b);
      int id = mp.get(ull(a) << 32 | b, -1);
      if (id == -1) yes();
      else yes(v.dist(x, y) != v.dist(x, id) + v.dist(y, id));
    } else {
      INT(a, b, c);
      --a, --b, --c;
      yes(v.dist(a, b) != v.dist(a, c) + v.dist(b, c));
    }
  }
}
#include "YRS/aa/main.hpp"