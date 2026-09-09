#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mint_t.hpp"

using T = M11;

void Yorisou() {
  INT(N, K);
  T s;
  FOR(k, K, N + 2) s += T(N + N - k + 1) * k / 2 - T(k - 1) * k / 2 + 1;
  print(s);
}

int main() { Yorisou(); }