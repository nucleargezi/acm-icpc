#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/rb/rb_dsu.hpp"

using dsu = rb_dsu;
void Yorisou() {
  INT(N, M, K);
  VEC(T3<int>, es, M);
  for (Z &[a, b, w] : es) --a, --b;

  INT(Q);
  VEC(int, q, Q);
  vc<int> I(Q);
  iota(all(I), 0);
  vc<int> EI(M);
  iota(all(EI), 0);

  dsu g(N);
  vc<ll> ans(Q);
  ll sm = 0;
  Z ae = [&](const vc<int> &I) {
    for (int i : I) {
      Z [a, b, _] = es[i];
      a = g[a], b = g[b];
      if (a != b) {
        sm += g.size(a) * g.size(b);
        g.merge(a, b);
      }
    }
  };

  Z f = [&](Z &f, int d, const vc<int> &EI, const vc<int> &I) -> void {
    if (I.empty()) return;
    if (EI.empty()) {
      for (int i : I) ans[i] = sm;
      return;
    }
    int t = g.time();
    ll cp = sm;
    vc<int> les, res;
    for (int i : EI) {
      Z [a, b, w] = es[i];
      if (w >> d & 1) res.ep(i);
      else les.ep(i);
    }
    vc<int> ls, rs;
    for (int i : I) {
      if (q[i] >> d & 1) rs.ep(i);
      else ls.ep(i);
    }
    if (K >> d & 1) {
      if (d) {
        ae(les);
        f(f, d - 1, res, ls);
        g.rb(t);
        sm = cp;
        ae(res);
        f(f, d - 1, les, rs);
      } else {
        ae(les);
        f(f, d - 1, {}, ls);
        g.rb(t);
        sm = cp;
        ae(res);
        f(f, d - 1, {}, rs);
      }
    } else {
      if (d) {
        f(f, d - 1, les, ls);
        f(f, d - 1, res, rs);
      } else {
        f(f, d - 1, {}, I);
      }
    }
    g.rb(t);
    sm = cp;
  };
  f(f, 29, EI, I);
  FOR(i, Q) print(ans[i]);
}

int main() {
  Yorisou();
  return 0;
}