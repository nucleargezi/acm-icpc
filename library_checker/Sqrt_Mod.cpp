#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/mod_sqrt.hpp"

void Yorisou() {
  INT(x, p);
  print(mod_sqrt(x, p));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}