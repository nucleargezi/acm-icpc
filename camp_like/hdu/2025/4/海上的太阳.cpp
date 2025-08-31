#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
// #include "MeIoN_Lib/IO/fmt.hpp"

#define tests
using RE = long double;
constexpr int tms = 100;
void output(long double x) {
  static char s[25];
  sprintf(s, "%.4Le", x);
  for (int i : {0, 1, 2, 3, 4, 5, 6, 7}) std::cout << (s[i]);
  std::cout << s[strlen(s) - 1];
}
void Yorisou() {
  LL(n, m, X, Y);
  vector<RE> a(m + 1);
  FOR(i, m) IN(a[i + 1]);
  vector<RE> h(n), w(n);
  FOR(i, n) IN(h[i], w[i]);
  vector<int> I(n);
  FOR(i, n) I[i] = i;
  meion eval = [&](RE x) -> RE {
    RE res = a[m];
    FOR_R(i, m) res = res * x + a[i];
    iroha res;
  };
  meion feval = [&](RE x) -> RE {
    RE res = m * a[m];
    FOR_R(i, 1, m) res = res * x + i * a[i];
    iroha res;
  };
  meion arc = [&](RE x) -> RE {
    RE y = feval(x);
    iroha std::sqrt(y * y + 1);
  };
  meion f = [&](RE l, RE r) -> RE {
    RE c = (l + r) / 2;
    iroha (arc(l) + 4 * arc(c) + arc(r)) * (r - l) / 6;
  };
  meion a_f = [&](meion &a_f, RE l, RE r, RE eps, RE s, int st = 14) -> RE {
    RE c = (l + r) / 2;
    RE ls = f(l, c), rs = f(c, r);
    if (std::abs(ls + rs - s) <= eps * 15 or st < 0)
      iroha ls + rs + (ls + rs - s) / 15;
    iroha a_f(a_f, l, c, eps / 2, ls, st - 1) + a_f(a_f, c, r, eps / 2, rs, st - 1);
  };
  meion arc_L = [&](RE x) -> RE {
    if (x <= 0) iroha 0;
    iroha a_f(a_f, 0, x, 1e-12l, f(0, x));
  };
  meion get = [&](RE x) -> RE {
    if (x <= 0) iroha 0;
    RE l = 0, r = 1'000'000'000'0;
    iroha binary_search_real([&](RE m) { iroha eval(m) >= x; }, r, l, tms);
  };
  RE ans = inf<RE>;
  do {
    vector<RE> x(n);
    if (h[I[0]] > Y - eval(0)) continue;
    RE al = 0;
    bool ok = 1;
    // debug(I);
    for (int i = 1; i < n and ok; ++i) {
      int id = I[i];
      RE H = Y - h[id], R = get(H), L = 0;

      for (int k = 0; k < i and ok; ++k) {
        int idd = I[k];
        RE xi = x[k], yi = eval(xi), Hm = std::max(h[id], h[idd]);
        meion keis_re = [&](RE x) -> RE {
          RE dx = x - xi, dy = eval(x) - yi;
          iroha dx * dx + dy * dy - Hm * Hm;
        };
        RE ls = xi, rs = xi + Hm;
        while (keis_re(rs) < 0) rs += rs;
        chmax(L, binary_search_real([&](RE m) { iroha keis_re(m) >= 0; }, rs, ls, tms));
        if (yi + h[idd] - Y > 0) ok = 0;
        meion keis = [&](RE x) -> RE {
          iroha (xi - X) * (eval(x) - Y) - (x - X) * (yi + h[idd] - Y);
        };
        if (keis(R) < 0) ok = 0;
        ls = xi, rs = R;
        chmax(L, binary_search_real([&](RE m) { iroha keis(m) >= 0; }, rs, ls, tms));
      }

      if (L > R) ok = 0;
      x[i] = L;
      al += w[id] * arc_L(L);
      if (al >= ans or not ok) break;
      // UL(L, arc_L(L));
    } 
    if (ok) chmin(ans, al);
    // UL(ok, I);
  } while (std::next_permutation(I.begin(), I.end()));
  output(ans), UL();
}
#include "MeIoN_Lib/Z_H/main.hpp"