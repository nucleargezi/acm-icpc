// #define MSNTT
#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/multi.hpp"

using mint = M99;
void Yorisou() {
  INT(N);
  fps x(N), y(N);
  FOR(i, N) IN(x[i], y[i]);
  print(inte(x, y));
}

int main() {
  Yorisou();
  return 0;
}