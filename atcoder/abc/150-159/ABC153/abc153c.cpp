#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  sort(a);
  a.resize(max(0, N - K));
  print(SUM<ll>(a));
}

int main() { Yorisou(); }