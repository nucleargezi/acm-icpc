#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/nth_root.hpp"

void Yorisou() {
  INT(Q);
  FOR(Q) {
    INT(n, m, k);
    Z a = mod_nth_root(k, n, m);
    print(si(a));
    if (si(a)) print(a);
  }
}

int main() {
  Yorisou();
  return 0;
}