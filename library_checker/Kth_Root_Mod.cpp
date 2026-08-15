#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/nth_root_one.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    INT(n, k, p);
    print(mod_nth_root_one(k, n, p));
  }
}

int main() {
  Yorisou();
  return 0;
}