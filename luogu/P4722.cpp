#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/hlpp.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  VEC(T3<int>, es, M);
  for (Z &[a, b, c] : es) --a, --b;
  print(hlpp(N, es).flow(s, t));
}

int main() {
  Yorisou();
  return 0;
}