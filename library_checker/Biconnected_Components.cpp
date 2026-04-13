#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/block_cut.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<0, 0>(M);
  graph v = block_cut(g);
  print(v.N - g.N);
  FOR(n, N, v.N) {
    vc<int> s;
    for (Z &&e : v[n]) s.ep(e.to);
    print(si(s), s);
  }
}

int main() {
  Yorisou();
  return 0;
}