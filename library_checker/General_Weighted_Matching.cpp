#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower_w.hpp"

void Yorisou() {
  INT(N, M);
  flower_w<ll> g(N);
  FOR(M) {
    INT(a, b, c);
    g.add(a, b, c);
  }
  Z s = g.slv();
  vc<PII> rs;
  FOR(i, N) {
    int t = g.ma[i + 1] - 1;
    if (t and i < t) rs.ep(i, t);
  }
  print(si(rs), s);
  for (var [a, b] : rs) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}