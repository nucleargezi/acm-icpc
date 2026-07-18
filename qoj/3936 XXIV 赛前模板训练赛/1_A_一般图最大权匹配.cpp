#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower_w.hpp"

void Yorisou() {
  INT(N, M);
  flower_w<int> g(N);
  FOR(M) {
    INT(a, b, c);
    g.add(a, b, c);
  }
  int s = g.slv();
  vc<PII> es;
  FOR(i, 1, N + 1) if (g.ma[i] > i) es.ep(i - 1, g.ma[i] - 1);
  print(si(es), s);
  for (var [a, b] : es) print(a, b);
}

int main() {
  Yorisou();
  return 0;
}