#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  int c = 0;
  while (N) ++c, N /= K;
  print(c);
}

int main() { Yorisou(); }