#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/lag.hpp"

using T = M99;
void Yorisou() {
  INT(N, c);
  fps a(N), b(N);
  FOR(i, N) IN(a[i], b[i]);
  print(lag_dis(a, b, c));
}

int main() { Yorisou(); }