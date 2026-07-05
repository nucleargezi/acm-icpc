#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/hld.hpp"
#include "YRS/ttr/tree_ball_ins.hpp"

void Yorisou() {
  INT(N);
  vc<vc<int>> g(N + N - 1);
  Z ad = [&](int a, int b) { g[a].ep(b), g[b].ep(a); };
  FOR(i, N - 1) {
    INT(a, b);
    --a, --b;
    ad(a, i + N), ad(b, i + N);
  }
  hld v(g, 0);
  using DS = tree_ball_ins<int>;
  DS ds(N, g, v);

  INT(Q);
  vc<PII> a;
  vc<DS::dat> pr, su;
  FOR(Q) {
    INT(sz);
    a.resize(sz);
    pr.resize(sz + 1);
    su.resize(sz + 1);
    pr[0] = su[sz] = {};
    for (Z &[i, r] : a) IN(i, r), --i, r <<= 1;
    FOR(i, sz) pr[i + 1] = ds.me(pr[i], ds.get(a[i]));
    FOR_R(i, sz) su[i] = ds.me(su[i + 1], ds.get(a[i]));
    ll A = ds.ins(pr[sz]), B = 0;
    FOR(i, sz) B += ds.ins(ds.me(pr[i], su[i + 1]));
    print(B - ll(sz - 1) * A);
  }
}

int main() {
  Yorisou();
  return 0;
}