#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/tr/ddp.hpp"

using mint = M99;
struct DP {
  struct X {
    mint a, b, cnt, ans;
  };
  static X rak(X &L, X &R) { return {L.a, L.b, L.cnt + R.cnt, L.ans + R.ans}; }
  static X com(X &L, X &R) {
    mint a = L.a, b = L.b;
    mint c = R.a, d = R.b;
    mint aa = a * c, bb = a * d + b;
    mint cnt = L.cnt + R.cnt;
    mint ans = L.ans + a * R.ans + b * R.cnt;
    return {aa, bb, cnt, ans};
  }
};
void Yorisou() {
  INT(N, Q);
  VEC(mint, a, N);
  vc<pair<mint, mint>> es(N - 1);
  graph g(N);
  g.es.reserve(N - 1);
  FOR(i, N - 1) {
    INT(x, y);
    g.add(x, y);
    IN(es[i]);
  }
  g.build();
  hld v(g);
  
  Z sing = [&](int i) -> DP::X {
    if (i == 0) { return {1, 0, 1, a[i]}; }
    int e = v.ve(i);
    return {es[e].fi, es[e].se, 1, es[e].fi * a[i] + es[e].se};
  };
  ddp_t<int, DP> dp(v, sing);
  FOR(Q) {
    INT(t);
    if (t == 0) {
      INT(i, x);
      a[i] = x;
      dp.set(i, sing(i));
    } else {
      INT(i, b, c);
      es[i].fi = b, es[i].se = c;
      i = v.ev(i);
      dp.set(i, sing(i));
    }
    print(dp.prod().ans);
  }
}

int main() {
  Yorisou();
  return 0;
}