#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/mat_inv.hpp"

void Yorisou() {
  INT(N);
  vc<bs> a(N);
  FOR(i, N) {
    STR(s);
    a[i] = s;
  }
  a = mat_inv2(a);
  if (a.empty()) return print(-1);
  FOR(i, N) print(a[i]);
}

int main() {
  Yorisou();
  return 0;
}