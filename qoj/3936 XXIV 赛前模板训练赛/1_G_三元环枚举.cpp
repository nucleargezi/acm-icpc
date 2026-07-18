#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"
#include "YRS/gg/c3/enum_c3.hpp"

using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N);
  VEC(PII, es, M);
  mint s;
  enum_c3(N, es, [&](int i, int k, int j) { s += a[i] * a[k] * a[j]; });
  print(s);
}

int main() {
  Yorisou();
  return 0;
}