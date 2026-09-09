#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b);
  print(a > b ? "safe" : "unsafe");
}

int main() { Yorisou(); }