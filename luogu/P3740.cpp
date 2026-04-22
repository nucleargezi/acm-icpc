#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/chtholly/chtholly_fset.hpp"

void Yorisou() {
  INT(N, Q);
  chtholly_fset<int> se(N, 0);
  FOR(i, Q) {
    INT(l, r);
    --l;
    se.set(l, r, i + 1);
  }
  vc<u8> a(N);
  for (var [l, r, x] : se.get_all()) if (x) a[x - 1] = 1;
  print(SUM<int>(a));
}

int main() {
  Yorisou();
  return 0;
}