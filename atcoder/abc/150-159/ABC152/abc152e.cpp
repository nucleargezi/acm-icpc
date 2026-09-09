#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/factors.hpp"

using T = M11;

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  T s;
  for (T x : a) s += x.inv();
  int sz = QMAX(a);
  vc<int> lpf = lpf_table(sz), c(sz + 1);
  for (int x : a) {
    for (Z[e, p] : factor(x, lpf)) chmax(c[e], p);
  }
  FOR(i, sz + 1) if (c[i]) s *= T(i).pow(c[i]);
  print(s);
}

int main() { Yorisou(); }