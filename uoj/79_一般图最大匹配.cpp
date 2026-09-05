#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flower.hpp"

void Yorisou() {
  INT(N, M);
  flower g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g.add(a, b);
  }
  print(g.slv());
  Z s = move(g.ma);
  s.resize(N);
  FOR(i, N) s[i] = s[i] == N ? 0 : s[i] + 1;
  print(s);
}

int main() { Yorisou(); }