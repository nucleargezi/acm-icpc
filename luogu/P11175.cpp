#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/modfast_d.hpp"

void Yorisou() {
  INT(p, g, Q);
  modfast_d X(p, g);
  FOR(Q) {
    INT(x);
    print(X.log_r(x));
  }
}

int main() {
  Yorisou();
  return 0;
}