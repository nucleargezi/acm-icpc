#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  INT(a, b, c);
  if (a == b and a != c) return Yes();
  if (a == c and a != b) return Yes();
  if (b == c and a != c) return Yes();
  No();
}

int main() { Yorisou(); }