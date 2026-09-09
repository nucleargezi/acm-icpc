#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K, M);
  VEC(int, a, N - 1);
  int s = SUM<int>(a) - M * N;
  FOR(i, K + 1) if (s + i >= 0) return print(i);
  print(-1);
}

int main() { Yorisou(); }