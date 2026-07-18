#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/nim/wythoff.hpp"

void Yorisou() {
  INT(a, b);
  print(wythoff(a, b));
}

int main() {
  Yorisou();
  return 0;
}