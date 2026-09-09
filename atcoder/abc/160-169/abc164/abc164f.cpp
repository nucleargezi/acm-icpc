#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void fl() { print(-1); }

void Yorisou() {
  INT(N);
  vc<ull> s(N), t(N), u(N), v(N);
  IN(s, t, u, v);
  retsu<ull> ans(N, N);
  FOR(bit, 64) {
    retsu<int> tt(N, N, -1);
    vc<array<ull, 2>> a(N), b(N);
    Z ck = [&](const vc<ull>& a, const vc<ull>& b, int ok) -> bool {
      int x;
      FOR(i, N) {
        x = a[i] & 1;
        if (b[i] == (uint)x) continue;
        FOR(k, N) {
          int p = ok ? tt[k][i] : tt[i][k];
          if (~p and p != x) return 0;
          (ok ? tt[k][i] : tt[i][k]) = x;
        }
      }
      return 1;
    };
    if (not ck(u, s, 0) or not ck(v, t, 1)) return fl();
    FOR(i, N) FOR(k, N) {
      if ((u[i] & 1) == (v[k] & 1)) tt[i][k] = u[i] & 1;
      if (tt[i][k] == -1) tt[i][k] = 0;
      a[i][tt[i][k]]++;
      b[k][tt[i][k]]++;
    }
    Z go = [&](const vc<ull>& s, const vc<ull>& u, const vc<ull>& t,
               const vc<ull>& v, vc<array<ull, 2>>& a, vc<array<ull, 2>>& b,
               int ok) {
      FOR(i, N) if (s[i] and (u[i] & 1)) {
        if (a[i][1]) continue;
        FOR(k, N) {
          if (not t[k] and not(v[k] & 1) and b[k][0] > 1) {
            (ok ? tt[k][i] : tt[i][k]) = 1;
            --a[i][0], --b[k][0];
            ++a[i][1], ++b[k][1];
            break;
          }
        }
      }
    };
    go(s, u, t, v, a, b, 0), go(t, v, s, u, b, a, 1);
    FOR(i, N) {
      if (s[i] == 0 and (u[i] & 1) == 1 and a[i][1] != (uint)N) return fl();
      if (s[i] == 0 and (u[i] & 1) == 0 and a[i][1] == (uint)N) return fl();
      if (s[i] == 1 and (u[i] & 1) == 1 and a[i][1] == 0) return fl();
      if (s[i] == 1 and (u[i] & 1) == 0 and a[i][1] != 0) return fl();
      if (t[i] == 0 and (v[i] & 1) == 1 and b[i][1] != (uint)N) return fl();
      if (t[i] == 0 and (v[i] & 1) == 0 and b[i][1] == (uint)N) return fl();
      if (t[i] == 1 and (v[i] & 1) == 1 and b[i][1] == 0) return fl();
      if (t[i] == 1 and (v[i] & 1) == 0 and b[i][1] != 0) return fl();
    }
    FOR(i, N) FOR(k, N) if (tt[i][k]) ans[i][k] |= 1ull << bit;
    FOR(i, N) u[i] >>= 1, v[i] >>= 1;
  }
  print(ans);
}

int main() { Yorisou(); }