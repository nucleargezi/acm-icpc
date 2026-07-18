#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    LL(x);
    Yes(ptest(x));
  }
}

int main() {
  Yorisou();
  return 0;
}