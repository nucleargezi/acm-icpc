#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"
#include "YRS/gg/bct.hpp"
#include "YRS/ttr/doubling.hpp"

void yorisou() {
  INT(N, M);
  vc<vc<int>> v(N << 1), g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    v[a].ep(b), v[b].ep(a);
  }
  vc<int> c(N << 1), to;
  FOR(i, N) {
    to.clear();
    for (int x : v[i << 1]) c[x] |= 1;
    for (int x : v[i << 1 | 1]) c[x] |= 2;
    for (int x : v[i << 1]) {
      int a = x, b = x ^ 1;
      if (((c[a] & 1) and (c[b] & 2)) or 
          ((c[a] & 2) and (c[b] & 1))) {
        to.ep(x >> 1);
      }
    }
    for (int x : v[i << 1]) c[x] = 0;
    for (int x : v[i << 1 | 1]) c[x] = 0;
    unique(to);
    for (int x : to) if (i != x) g[i].ep(x);
  }

  vc<vc<int>> ng = bct(g);
  int cc = si(ng);
  doubling db(ng);
  var L = db.L;
  var R = db.R;

  dsu f(cc);
  FOR(i, cc) for (int x : ng[i]) f.merge(i, x);

  vc<PII> lr(cc, {cc + 1, -1});
  FOR(i, cc) {
    Z &[l, r] = lr[f[i]];
    chmin(l, L[i]), chmax(r, R[i]);
  }
  
  vc<int> pr(cc + 1);
  Z op = [&](PII lr, bool f) -> void {
    var [l, r] = lr;
    if (f) ++pr[l], --pr[r];
    else --pr[l], ++pr[r];
  };
  Z apply = [&](int x, int rt, bool a = 1) -> void {
    if (x == rt) return op(lr[f[x]], a);
    if (not db.ins(rt, x)) return op({L[x], R[x]}, a);
    x = db.jump(x, rt, 1);
    int l = L[x], r = R[x];
    var [LL, RR] = lr[f[x]];
    op({LL, l}, a);
    op({r, RR}, a);
  };

  FOR(i, N) for (int x : v[i << 1]) {
    if (x == (i << 1 | 1)) apply(i, i, 1);
  }
  vc<int> q;
  FOR(i, N << 1) {
    q.clear();
    for (int x : v[i]) q.ep(x >> 1);
    sort(all(q));
    int sz = si(q);
    FOR(k, sz - 1) if (q[k] == q[k + 1]) {
      int x = q[k];
      apply(x, x, 1);
      if (f[i >> 1] == f[x]) apply(i >> 1, x, 0);
    }
  }
  FOR(i, cc) pr[i + 1] += pr[i];
  FOR(i, N) print(pr[L[i]] > 0 ? "Yes" : "No");
}

int main() {
  int T = 1;
  FOR(T) yorisou();
  return 0;
}