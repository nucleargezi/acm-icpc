#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower.hpp"

void Yorisou() {
  INT(N, M);
  flower g(N);
  FOR(M) {
    INT(x, y);
    g.add(x, y);
  }
  print(g.sol());
  var m = g.m;
  FOR(i, N) if (m[i] != N and i < m[i]) print(i, m[i]);
}

int main() {
  Yorisou();
  return 0;
}