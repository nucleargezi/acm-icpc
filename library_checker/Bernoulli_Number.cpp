#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/poly/f/bernoulli.hpp"

using mint = M99;
fps_t<mint> X;
void Yorisou() {
  INT(N);
  print(X.bernoulli(N));
}

int main() {
  Yorisou();
  return 0;
}