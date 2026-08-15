#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/mat_det.hpp"

void Yorisou() {
  INT(N);
  vc<bs> a(N);
  FOR(i, N) {
    STR(s);
    a[i] = s;
  }
  print(mat_det2(a));
}

int main() {
  Yorisou();
  return 0;
}