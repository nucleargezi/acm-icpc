#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/circle.hpp"

using re = ld;
constexpr re eps = 1e-10;
void Yorisou() {
  INT(N, K);
  vc<circle<ll>> a(N);
  for (Z &[O, R] : a) IN(O, R);

  int mx = 0;
  FOR(i, N) {
    vc<pair<re, int>> dat;
    FOR(k, N) if (i != k) {
      Z O = a[i].O - a[k].O;
      re ang = O.angle();
      re d = O.length();
      re r = a[i].R, rr = a[k].R;
      re ls = ang - asin((rr - r) / d), rs = ang + asin((rr + r) / d);
      rs -= eps;
      FOR(d, -2, 3) {
        re l = ls + (pi + pi) * d, r = rs + (pi + pi) * d;
        chmax(l, 0);
        chmin(r, pi + pi);
        if (l < r) dat.ep(l, 1), dat.ep(r, -1);
      }
      ls = (ang + pi) - asin((r + rr) / d);
      rs = (ang + pi) + asin((rr - r) / d);
      rs -= eps;
      FOR(d, -2, 3) {
        re l = ls + (pi + pi) * d, r = rs + (pi + pi) * d;
        chmax(l, 0);
        chmin(r, pi + pi);
        if (l < r) dat.ep(l, 1), dat.ep(r, -1);
      }
    }
    sort(dat);
    for (int s = 0; var [a, b] : dat) s += b, chmax(mx, s);
  }
  ll rs = N;
  FOR(i, K) rs += 1 + mx + i;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}