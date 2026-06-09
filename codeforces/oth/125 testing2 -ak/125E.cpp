#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

using re = ld;
void Yorisou() {
  INT(N, M, K);
  vc<tuple<re, int, int, int>> e(M);
  for (int t = 0; Z &[w, c, a, b] : e) {
    IN(a, b, w);
    --a, --b;
    c = t++;
  }

  dsu g(N);
  vc<int> rs;
  Z ck = [&](re k) {
    rs.clear();
    g.reset();
    for (Z &[w, c, a, b] : e) if (not(a and b)) w += k;
    int s = 0;
    for (int i : argsort(e)) {
      var [w, c, a, b] = e[i];
      if (g.merge(a, b)) s += not(a and b), rs.ep(i + 1);
    }
    for (Z &[w, c, a, b] : e) if (not(a and b)) w -= k;
    return s;
  };
  re l = -1'000'00.l, r = -l;
  FOR(100) {
    re m = (l + r) / 2;
    int sk = ck(m);
    if (sk == K) return print(si(rs)), print(rs);
    (sk < K ? r : l) = m;
  }
  print(-1);
}

int main() {
  Yorisou();
  return 0;
}