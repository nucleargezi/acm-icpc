#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

// #define tests
using mint = M99;
static constexpr mint inv2 = 499122177;
void Yorisou() {
  LL(n);
  vector<vector<int>> v(n);
  FOR(n - 1) {
    LL(x, y);
    --x, --y;
    v[x] += y, v[y] += x;
  }
  FOR(i, n) v[i].shrink_to_fit();
  S(s);
  int cnt = std::ranges::count(s, 'w');
  vector<mint> vx(n);
  vx.shrink_to_fit();
  vector<mint> vy(n);
  vy.shrink_to_fit();
  vector<mint> dpx(n);
  dpx.shrink_to_fit();
  vector<mint> dppx(n);
  dppx.shrink_to_fit();
  vector<mint> dpy(n);
  dpy.shrink_to_fit();
  vector<mint> dppy(n);
  dppy.shrink_to_fit();
  vector<mint> sx(n);
  sx.shrink_to_fit();
  vector<mint> sy(n);
  sy.shrink_to_fit();
  vector<mint> bx(n);
  bx.shrink_to_fit();
  vector<mint> by(n);
  by.shrink_to_fit();
  vector<mint> cx(n);
  cx.shrink_to_fit();
  vector<mint> cy(n);
  cy.shrink_to_fit();
  FOR(i, n) {
    vx[i] = s[i] == 'r' ? 1 : s[i] == 'b' ? 0 : inv2;
    vy[i] = s[i] == 'r' ? 0 : s[i] == 'b' ? 1 : inv2;
  }
  [&]() {
    meion f = [&](meion &f, int n, int fa = -1) -> void {
      for (int t : v[n]) {
        if (t != fa) f(f, t, n);
      }
      if (fa != -1) v[n].erase(std::find(v[n].begin(), v[n].end(), fa));
    };
    f(f, 0);
  }();
  [&]() {
    meion f = [&](meion &f, int n) -> void {
      mint A, B, C, D, E, F;
      for (int t : v[n]) {
        f(f, t);
        A += dpx[t], B += dpx[t] * dpx[t], C += dppx[t];
        D += dpy[t], E += dpy[t] * dpy[t], F += dppy[t];
      }
      dpx[n] = vx[n] * (A + 1);
      dppx[n] = C + vx[n] * (A * A - B) + (dpx[n] - vx[n]) * 2 + vx[n];
      dpy[n] = vy[n] * (D + 1);
      dppy[n] = F + vy[n] * (D * D - E) + (dpy[n] - vy[n]) * 2 + vy[n];
    };
    f(f, 0);
  }();
  sx[0] = sy[0] = 0;
  [&]() {
    static meion ps = [](vector<mint> &v) {
      const int n = len(v);
      v.insert(v.begin(), 0);
      v.shrink_to_fit();
      FOR(i, n) v[i + 1] += v[i];
    };
    meion f = [&](meion &f, int n) -> void {
      vector<mint> px, py;
      for (int x : v[n]) {
        px += dpx[x];
        py += dpy[x];
      }
      meion sufx = px, sufy = py;
      ps(px), ps(py);
      reverse(sufx), reverse(sufy);
      ps(sufx), ps(sufy);
      reverse(sufx), reverse(sufy);
      FOR(i, len(v[n])) {
        int x = v[n][i];
        sx[x] = vx[x] * (vx[n] + sx[n] + vx[n] * (px[i] + sufx[i + 1]));
        sy[x] = vy[x] * (vy[n] + sy[n] + vy[n] * (py[i] + sufy[i + 1]));
        f(f, x);
      }
    };
    f(f, 0);
  }();
  FOR(i, n) {
    mint sa, sb, saa, sbb;
    for (int x : v[i]) sa += dppx[x], sb += dppy[x];
    cx[i] = dppx[i] - sa, cy[i] = dppy[i] - sb;
    sa = sx[i], sb = sy[i], saa = sx[i] * sx[i], sbb = sy[i] * sy[i];
    for (int x : v[i]) {
      mint g = vx[i] * dpx[x];
      sa = sa + g, saa = saa + g * g;
      g = vy[i] * dpy[x];
      sb = sb + g, sbb = sbb + g * g;
    }
    bx[i] = vx[i] + sa * 2 +
            (sa * sa - saa) * ((vx[i] == 0) ? 0 : mint(vx[i]).inv());
    by[i] = vy[i] + sb * 2 +
            (sb * sb - sbb) * ((vy[i] == 0) ? 0 : mint(vy[i]).inv());
  }
  mint ss;
  FOR(i, n) ss += cx[i] * by[i] + cy[i] * bx[i] - cx[i] * cy[i];
  print("{}", (dppx[0] * dppy[0] - ss) * mint(2).pow(cnt));
}
#include "MeIoN_Lib/Z_H/main.hpp"