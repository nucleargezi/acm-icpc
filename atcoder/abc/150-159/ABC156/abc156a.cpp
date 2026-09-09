#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(k, N);
  print(N + 100 * (10 - min(k, 10ll)));
}

int main() { Yorisou(); }