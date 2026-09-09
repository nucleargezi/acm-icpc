#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  unique(a);
  YES(si(a) == N);
}

int main() { Yorisou(); }