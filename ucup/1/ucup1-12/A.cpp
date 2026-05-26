#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/make_rooted.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  make_rooted(g, 0);
  Z f= [&](Z &f, int n) -> PII {
    int sz = si(g[n]);
    if (sz == 0) {
      PII rs = {0, 1};
      if (a[n]) swap(rs.fi, rs.se);
      return rs;
    } else {
      vc<int> d;
      int e = 0, c = 0;
      for (int x : g[n]) {
        var [a, b] = f(f, x);
        e += max(a, b);
        c += b >= a;
        d.ep(abs(a - b));
      }
      int m = QMIN(d);
      if (c & 1) return {e + a[n] - m, e + not a[n]};
      return {e + a[n], e + not a[n] - m};
    }
  };
  Z [x, y] = f(f, 0);
  print(max(x, y));
}

int main() {
  Yorisou();
  return 0;
}