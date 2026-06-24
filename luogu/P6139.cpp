#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  INT(N);
  sam_ex ss;
  FOR(i, N) {
    STR(s);
    for (int x = 0; int c : s) x = ss.add(x, c - 'a');
  }
  print(ss.count());
  print(si(ss));
}

int main() {
  Yorisou();
  return 0;
}