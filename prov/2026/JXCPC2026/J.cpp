#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/divisors.hpp"
#include "YRS/ds/un/dsu.hpp"

TE struct doubling {
  int N, n, t;
  const vc<vc<T>> &g;
  vc<int> L, R, d, fa[22];
  
  doubling(const vc<vc<T>> &g) : N(si(g)), g(g), L(N, -1), R(N), d(N) {
    n = 1;
    while (1 << n < N) ++n;
    FOR(i, n) fa[i].resize(N);
    t = 0;
    FOR_R(i, N) if (L[i] == -1) f(i, i);
    FOR(i, 1, n) FOR(k, N) fa[i][k] = fa[i - 1][fa[i - 1][k]];
  }
  
  void f(int n, int p) {
    fa[0][n] = p;
    L[n] = t++;
    for (int x : g[n]) if (x != p) d[x] = d[n] + 1, f(x, n);
    R[n] = t;
  }
  
  int lca(int a, int b) {
    if (d[a] < d[b]) swap(a, b);
    int w = d[a] - d[b];
    FOR(i, n) if (w >> i & 1) a = fa[i][a];
    if (a == b) return a;
    FOR_R(i, n) {
      int x = fa[i][a], y = fa[i][b]; 
      if (x != y) a = x, b = y;
    }
    return fa[0][a];
  }
  
  // L is in R
  bool ins(int a, int b) { return L[b] <= L[a] and L[a] < R[b]; }

  int la(int x, int k) {
    FOR(i, n) if (k >> i & 1) x = fa[i][x];
    return x;
  }

  int jump(int a, int b, int k) {
    int c = lca(a, b), w = d[a] + d[b] - 2 * d[c];
    if (w < k) return -1;
    return k > d[a] - d[b] ? la(b, w - k) : la(a, k);
  }
};
vc<int> pt = lpf_table(1'000'000);
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<vc<int>> v(1'000'001);
  FOR(i, N) {
    for (int x : divisor_by_lpf(a[i], pt)) {
      v[x].ep(i);
    }
  }
  int t = N;
  dsu g(N << 1);
  vc<int> w(N << 1, -1);
  vc<vc<int>> ng(N << 1);
  FOR_R(e, 1'000'001) {
    var a = v[e];
    int sz = si(a);
    FOR(i, sz - 1) {
      int x = a[i], y = a[i + 1];
      x = g[x], y = g[y];
      if (x != y) {
        g.set(t, x);
        g.set(t, y);
        w[t] = e;
        ng[t].ep(x);
        ng[t].ep(y);
        ++t;
      }
    }
  }
  doubling db(ng);
  FOR(Q) {
    INT(f, t);
    --f, --t;
    if (f == t) print(a[f]);
    else print(w[db.lca(f, t)]);
  }
}

int main() {
  Yorisou();
  return 0;
}