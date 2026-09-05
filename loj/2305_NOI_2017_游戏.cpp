#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/two_sat.hpp"
#include "YRS/aa/timer.hpp"

void Yorisou() {
  double st = sec();
  INT(N, d);
  STR(ra);
  INT(M);
  vc<T4<int>> e(M);
  FOR(i, M) {
    int x, y;
    char a, b;
    IN(x, a, y, b);
    --x, --y;
    a -= 'A', b -= 'A';
    e[i] = {x, y, a, b};
  }
  vc<int> p;
  FOR(i, N) {
    if (ra[i] == 'x') p.ep(i);
    else ra[i] -= 'a';
  }
  int G = 1;
  FOR(d) G *= 3;
  FOR(s, G) {
    int x = s;
    FOR(i, d) {
      int ms = x % 3;
      x /= 3, ra[p[i]] = ms;
    }
    sat g(3 * N);
    FOR(i, N) {
      int tp = ra[i];
      if (tp == 0) {
        g.ban(3 * i + 1, 3 * i + 2, 0, 0);
        g.ban(3 * i + 1, 3 * i + 2, 1, 1);
        g.set(3 * i + 0, 0);
      }
      if (tp == 1) {
        g.ban(3 * i + 0, 3 * i + 2, 0, 0);
        g.ban(3 * i + 0, 3 * i + 2, 1, 1);
        g.set(3 * i + 1, 0);
      }
      if (tp == 2) {
        g.ban(3 * i + 0, 3 * i + 1, 0, 0);
        g.ban(3 * i + 0, 3 * i + 1, 1, 1);
        g.set(3 * i + 2, 0);
      }
    }
    for (Z [x, y, a, b] : e) {
      g.ban(3 * x + a, 3 * y + b, 1, 0);
    }
    if (g.slv()) {
      Z &s = g();
      string ans(N, 'A');
      FOR(i, N) FOR(k, 3) if (s[3 * i + k]) ans[i] = 'A' + k;
      return print(ans);
    }
    if (sec() - st > 1.9) break;
  }
  print(-1);
}

int main() { Yorisou(); }