#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/Basic.hpp"
#include "YRS/ds/trie_bina.hpp"

#define tests 0
#define fl 0
#define DB 10
using trie = trie_bina<30, 1, int, int, 1 << 18>;
using np = trie::np;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  graph g(N);
  g.read_tree();
  tree v(g);
  vc<np> t(N + 1, nullptr);
  trie tr;
  FOR_R(i, N) t[i] = tr.add(t[i + 1], a[v.V[i]]);
  FOR(Q) {
    INT(op);
    if (op == 2) {
      INT(x, y, w);
      --x, --y;
      int s = 0;
      for (Z [l, r] : v.get_path_decomposition(x, y, 0)) {
        if (l > r) swap(l, r);
        chmax(s, tr.range_max(t[r + 1], t[l], w));
      }
      print(s);
    } else {
      INT(x, w);
      --x;
      int l = v.L[x], r = v.R[x];
      print(tr.range_max(t[r], t[l], w));
    }
  }
}
#include "YRS/aa/main.hpp"