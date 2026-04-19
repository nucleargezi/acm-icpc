#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/ptest.hpp"

void Yorisou() {
  LL(x);
  Yes(ptest(x));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}