#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/floor_root.hpp"

void Yorisou() {
  LL(x, k);
  print(floor_root(x, k));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}