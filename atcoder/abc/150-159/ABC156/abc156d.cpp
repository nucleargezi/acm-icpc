#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using T = M11;
binom<T> C;

void Yorisou() {
  INT(N, a, b);
  print(T(2).pow(N) - C.C_naive(N, a) - C.C_naive(N, b) - 1);
}

int main() { Yorisou(); }