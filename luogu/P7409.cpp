#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"
#include "YRS/ttr/fast_lca.hpp"

void Yorisou() {
  INT(N, Q);
  STR(s);
  FOR(i, N) s[i] -= 'a';
  reverse(s);
  sam ss(N);
  ss.build(s);
  vc<vc<int>> g(ss.build_dir_g());
  tr v(g, 0);
  fast_lca fs(v);

  vc<PII> es;
  vc<int> c(si(ss));
  FOR(Q) {
    INT(n);
    VEC(int, a, n);
    unique(a);
    for (int &x : a) ++c[x = ss.en[N - x]];
    fs.tree_compress(a, es);
    ll rs = 0;
    reverse(es);
    for (var [fi, ti] : es) {
      int n = a[fi], p = a[ti];
      rs += ll(c[p]) * c[n] * ss[p].sz;
      c[p] += c[n];
    }
    for (int x : a) c[x] = 0;
    print(rs);
  }
}

int main() {
  Yorisou();
  return 0;
}