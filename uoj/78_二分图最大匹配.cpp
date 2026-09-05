#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/BM_v.hpp"

void Yorisou() {
  INT(L, R, M);
  vc<vc<int>> g(L + R);
  FOR(M) {
    INT(a, b);
    --a, --b, b += L;
    g[a].ep(b);
    g[b].ep(a);
  }
  vc<int> a(L);
  int s = 0;
  for (var [f, t] : BM_v(g)()) {
    a[f] = t + 1 - L;
    ++s;
  }
  print(s);
  print(a);
}

int main() { Yorisou(); }