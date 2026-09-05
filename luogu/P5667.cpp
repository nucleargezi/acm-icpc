#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/lag.hpp"

using T = M99;
void Yorisou() {
  INT(N, M);
  VEC(T ,f, N + 1);
  print(lag<T>(f, M, N + 1));
}

int main() { Yorisou(); }