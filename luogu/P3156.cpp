#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  FOR(Q) {
    INT(i);
    --i;
    print(a[i]);
  }
}

int main() {
  Yorisou();
  return 0;
}