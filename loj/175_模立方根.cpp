#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/nth_root_one.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    INT(a, p);
    print(max(0, mod_nth_root_one(a, 3, p)));
  }
}

int main() { Yorisou(); }