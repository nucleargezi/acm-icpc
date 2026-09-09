#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;

void Yorisou() {
  LL(s);
  re a = re(s) / 3;
  print(a * a * a);
}

int main() { Yorisou(); }