#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  int s = 0, f = 0;
  FOR(i, N) {
    INT(a, b);
    f = f - a + b;
    chmax(s, f);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}