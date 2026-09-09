#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  set<string> se;
  FOR(N) {
    STR(s);
    se.eb(s);
  }
  print(si(se));
}

int main() { Yorisou(); }