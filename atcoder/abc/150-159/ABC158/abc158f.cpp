#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using T = M99;

void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  sort(a);
  min_heap<PII> q;
  vc<vc<int>> g(N);
  FOR_R(i, N) {
    var [x, d] = a[i];
    while (si(q) and q.top().fi < x + d) g[i].ep(pop(q).se);
    q.eb(x, i);
  }
  Z f = [&](Z &f, int n) -> T {
    T s = 1;
    for (int x : g[n]) s *= f(f, x);
    return s + 1;
  };
  T s = 1;
  while (si(q)) s *= f(f, pop(q).se);
  print(s);
}

int main() { Yorisou(); }