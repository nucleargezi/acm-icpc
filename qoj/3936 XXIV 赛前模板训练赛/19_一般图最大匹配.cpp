#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower.hpp"

void Yorisou() {
  INT(N, M);
  flower g(N);
  FOR(M) {
    INT(a, b);
    g.add(a, b);
  }
  print(g.slv());
  FOR(i, N) if (g.m[i] != N and g.m[i] > i) print(i, g.m[i]);
}

int main() {
  Yorisou();
  return 0;
}