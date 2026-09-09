#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using T = M11;
binom<T> C;

void Yorisou() {
  INT(N, K);
  T s;
  FOR(i, min(N + 1, K + 1)) s += C(N, i) * C(N - 1, i);
  print(s);
}

int main() { Yorisou(); }