#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(int, a, Q);
  Yes(SUM<int>(a) >= N);
}

int main() { Yorisou(); }