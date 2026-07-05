#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/mo_tree.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  tr v(g, 0);
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[a, b] : q) --a, --b;
  mo_tree mo(v, q);

  vc<int> c(QMAX(a) + 1);
  int s = 0;
  vc<int> rs(Q);
  Z ad = [&](int x) { s += not c[a[x]]++; };
  Z rm = [&](int x) { s -= not --c[a[x]]; };
  Z set = [&]() { ad(0); };
  mo.ke(set, ad, ad, rm, rm, [&](int i) { rs[i] = s; });

  for (int x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}