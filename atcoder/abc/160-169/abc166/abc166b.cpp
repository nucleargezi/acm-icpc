#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N, Q);
  vc<int> c(N, 1);
  FOR(Q) {
    INT(n);
    FOR(n) {
      INT(x);
      c[x - 1] = 0;
    }
  }
  print(SUM<int>(c));
}

int main() { Yorisou(); }