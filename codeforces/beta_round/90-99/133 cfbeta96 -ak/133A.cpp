#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  YES(count(all(s), 'H') + count(all(s), 'Q') + count(all(s), '9'));
}

int main() {
  Yorisou();
  return 0;
}