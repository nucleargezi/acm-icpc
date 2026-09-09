#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using T = M99;
binom<T> C;

void Yorisou() {
  INT(N, M, K);
  T s, c = M;
  FOR_R(i, N) {
    T f = c * C(N - 1, i);
    if (i <= K) s += f;
    c *= M - 1;
  }
  print(s);
}

int main() { Yorisou(); } 