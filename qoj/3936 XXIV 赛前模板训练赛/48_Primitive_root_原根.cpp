#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/primitive_root.hpp"

void Yorisou() {
  LL(x);
  print(primitive_root(x));
}

int main() {
  Yorisou();
  return 0;
}