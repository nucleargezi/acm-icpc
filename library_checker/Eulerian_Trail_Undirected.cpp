#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/g/euler_walk.hpp"

void Yorisou() {
  INT(N, M);
  graph g(N);
  g.sc<0, 0>(M);
  vc<int> v = euler_walk(g);
  if (v.empty()) return print("No");
  print("Yes");
  vc<int> es = vs_to_es(g, v);
  print(v);
  print(es);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}