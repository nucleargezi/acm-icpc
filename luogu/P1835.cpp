#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/ml.hpp"

void Yorisou() {
  INT(l, r);
  --l;
  print(prim_count(r) - prim_count(l));
}

int main() {
  Yorisou();
  return 0;
}