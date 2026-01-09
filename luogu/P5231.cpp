#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/string/SA/SA.hpp"
#include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/monoid/min.hpp"

#define tests 0
#define fl 0
#define DB 10
template <typename Str>
struct DS {
  Str s;
  int N;
  SA sa;
  Seg<monoid_min<int>> st;

  DS(const Str &s) : s(s), N(len(s)), sa(s) {
    sa.sa.clear();
    sa.sa.shrink_to_fit();
    st.build(sa.lcp);
    sa.lcp.clear();
    sa.lcp.shrink_to_fit();
  }
};
void Yorisou() {
  INT(N, Q);
  STR(s);
  s += 'Z' + 1;
  vc<int> siz(Q);
  vc<char> q(Q);
  string t;
  t.reserve(100);
  FOR(i, Q) {
    IN(t);
    q[i] = t[0];
    siz[i] = len(t);
    s += t;
    s += '&';
  }
  t.clear();
  t.clear();
  s.shrink_to_fit();
  DS sa(s);
  s.clear();
  s.shrink_to_fit();
  vc<int> go;
  go.reserve(N);
  FOR(i, N) go.ep(sa.sa.rk[i]);
  sort(go);
  int sz = N + 1;
  FOR(i, Q) {
    int p = sa.sa.rk[sz];
    sz += siz[i] + 1;
    int it = lb(go, p);
    int ans = 0;
    if (it != len(go)) {
      int x = go[it];
      chmax(ans, sa.st.prod(min(p, x), max(p, x)));
    }
    --it;
    if (it >= 0) {
      int x = go[it];
      chmax(ans, sa.st.prod(min(p, x), max(p, x)));
    }
    print(ans);
  }
}
#include "YRS/aa/main.hpp"