#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/lgv.hpp"
#include "YRS/mod/binom.hpp"

binom<M99> C;
void Yorisou() {
  INT(N, M);
  VEC(PII, a, M);
  print(lgv(M, [&](int i, int k) -> int {
    int l = a[i].fi, r = a[k].se;
    if (l > r) return 0;
    return C(r - l + N - 1, r - l).val();
  }, 998244353));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}