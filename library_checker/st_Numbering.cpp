#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/st_numer.hpp"

void Yorisou() {
  INT(N, M, s, t);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    g[a].ep(b);
    g[b].ep(a);
  }
  
  Z rs = st_number(g, s, t);
  if (rs.empty()) No();
  else Yes(), print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}