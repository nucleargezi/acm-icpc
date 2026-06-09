#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/tr.hpp"

using re = ld;
void Yorisou() {
  INT(N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  tr v(g, 0);
  vc<re> p(N), q(N);
  vc<int> x(N), y(N);
  FOR(i, N) IN(x[i], y[i]);
  ll s = SUM<ll>(x), ss = SUM<ll>(y);
  FOR(i, N) p[i] = (re)x[i] / s, q[i] = (re)y[i] / ss;
  p = pre_sum(rearrange(p, v.V));
  re rs = 0;
  FOR(i, 1, N) {
    int l = v.L[i], r = v.R[i];
    re a = p[r] - p[l], b = q[v.fa[i]];
    rs += (r - l) * a * b;
    a = 1 - a, b = q[i];
    rs += (N + l - r) * a * b;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}