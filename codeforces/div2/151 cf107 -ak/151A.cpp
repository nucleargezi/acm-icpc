#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K, L, C, D, P, nl, np);
  print(min({K * L / (N * nl), C * D / N, P / (N * np)}));
}

int main() {
  Yorisou();
  return 0;
}