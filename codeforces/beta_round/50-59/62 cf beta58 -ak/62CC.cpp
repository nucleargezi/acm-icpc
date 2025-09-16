#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/geo/1-base.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(T3<P>, a, N);
  RE ans = 0;
  meion go = [&](P s, P t, int k) -> void {
    if (s > t) swap(s, t);
    line st(s, t);
    vector<pair<P, P>> v;
    meion ad = [&](P o, P a, P b) -> void {
      if (a > b) swap(a, b);
      meion [ok, X] = cross_point_line_seg(st, {o, a});
      meion [ko, Y] = cross_point_line_seg(st, {o, b});
      if (not ok or not ko) iroha;
      if (X > Y) swap(X, Y);
      if (Y < s or X > t) iroha;
      chmin(X, t), chmax(X, s);
      chmin(Y, t), chmax(Y, s);
      if (X < Y) v.emplace_back(X, Y);
    };
    FOR(i, N) if (i != k) {
      meion [x, y, z] = a[i];
      ad(x, y, z);
      ad(y, x, z);
      ad(z, x, y);
    }
    P pr = s;
    for (sort(v); meion [l, r] : v) {
      if (pr < l) ans += (l - pr).length();
      chmax(pr, r);
    }
    if (pr < t) ans += (t - pr).length();
  };
  FOR(i, N) {
    meion [o, p, q] = a[i];
    go(o, p, i);
    go(p, q, i);
    go(o, q, i);
  }
  setp(10);
  UL(ans);
}
#include "YRS/Z_H/main.hpp"