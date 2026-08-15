#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/pell.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    LL(D);
    print(pell<i128>(D, 1));
    print(pell<i128>(D, 0));
  }
}

int main() {
  Yorisou();
  return 0;
}