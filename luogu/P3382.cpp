#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/golden_search.hpp"

using re = ld;
void Yorisou() {
  INT(N);
  ++N;
  REAL(l, r);
  VEC(re, a, N);
  reverse(a);
  print(golden_search<re, 0>([&](re x) {
    re s = 0, w = 1;
    FOR(i, N) s += a[i] * w, w *= x;
    return s;
  }, l, r, 100).se);
}

int main() {
  Yorisou();
  return 0;
}