#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/tetration.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    INT(a, b, p);
    print(tetration(a, b, p));
  }
}

int main() {
  Yorisou();
  return 0;
}