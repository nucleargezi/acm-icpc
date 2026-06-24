#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/tree_sa.hpp"
#include "YRS/ds/seg/segd_t.hpp"
#include "YRS/ds/wave/sswave.hpp"

struct MX {
  using X = PII;
  
  static X op(const X &a, const X &b) {
    if (a.fi == -1) return b;
    if (b.fi == -1) return a;
    return {a.fi + b.fi, b.se};
  }

  static X unit() { return {-1, -1}; }

  static constexpr bool commute = 1;
};

using DS = segd_t<MX, 1>;
using np = DS::np;
void Yorisou() {
  INT(N, Q);
  vc<vc<int>> g(N);
  FOR(i, 1, N) {
    INT(f);
    --f;
    g[f].ep(i);
  }
  VEC(int, s, N);
  tree_sa sa(g, 0, s);
  vc<int> rk(N);
  FOR(i, N) rk[sa.sa[i]] = N - i;

  DS seg(0, N);
  vc<np> t(N);
  vc<int> L(N), R(N), dat(N);
  int tt = 0;
  Z f = [&](Z &f, int n) -> void {
    dat[tt] = rk[n];
    L[n] = tt++;
    t[n] = seg.set(t[n], rk[n] - 1, {1, n + 1});
    for (int x : g[n]) t[x] = t[n], f(f, x);
    R[n] = tt;
  };
  f(f, 0);
  sswave wm(dat);

  FOR(Q) {
    INT(op, x);
    --x;
    if (op == 1) {
      print(rk[x]);
    } else if (op == 2) {
      INT(K);
      int r = seg.maxr(t[x], [&](PII s) { return s.fi < K; }, 0);
      print(seg.prod(t[x], r, r + 1).se);
    } else {
      INT(K);
      int l = L[x], r = R[x];
      print(sa.sa[N - wm.kth(l, r, K - 1)] + 1);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}