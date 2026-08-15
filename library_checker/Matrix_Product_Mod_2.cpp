#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/mat_prod.hpp"

void Yorisou() {
  INT(N, M, Q);
  vc<bs> a(N), b(M);
  FOR(i, N) {
    STR(s);
    a[i] = s;
  }
  FOR(i, M) {
    STR(s);
    b[i] = s;
  }
  a = mat_prod2(a, b);
  FOR(i, N) print(a[i]);
}

int main() {
  Yorisou();
  return 0;
}