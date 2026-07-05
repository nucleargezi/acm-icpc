#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<char> c(N);
  for (int &x : a) {
    --x;
    if (x < N and x >= 0) c[x] = 1;
  }
  print(N - SUM<int>(c));
}

int main() {
  Yorisou();
  return 0;
}