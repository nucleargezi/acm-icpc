#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/trig.hpp"

using mint = M99;
void Yorisou() {
  INT(N, op);
  VEC(mint, f, N);
  print(op ? atan(f) : asin(f));
}

int main() { Yorisou(); }