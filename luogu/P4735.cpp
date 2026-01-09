#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/trie_bina.hpp"

#define tests 0
#define fl 0
#define DB 10
using trie = trie_bina<25, true, int, int>;
using np = trie::np;
void Yorisou() {
  INT(N, Q);
  trie_bina<25, 1, int, int> g;
  vc<int> a(N + 1);
  FOR(i, 1, N + 1) IN(a[i]), a[i] ^= a[i - 1];
  vc<np> t;
  np s = nullptr;
  FOR(i, N + 1) {
    s = g.add(s, a[i]);
    t.ep(s);
  }
  FOR(Q) {
    CH(op);
    if (op == 'A') {
      INT(x);
      a.ep(x);
      ++N;
      a[N] ^= a[N - 1];
      s = g.add(s, a[N]);
      t.ep(s);
    } else {
      INT(l, r, w);
      --l, --r;
      w ^= a[N];
      np x = l ? t[l - 1] : nullptr, y = t[r];
      print(g.range_max(x, y, w));
    }
  }
}
#include "YRS/aa/main.hpp"