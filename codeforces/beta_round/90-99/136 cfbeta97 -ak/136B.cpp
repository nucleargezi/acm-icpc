#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

int pw(int a, int b) {
  int s = 1;
  FOR(b) s *= a;
  return s;
}

void Yorisou() {
  INT(a, b);
  int c = 0;
  for (int i = 0; a or b; ++i) {
    c += (b % 3 - a % 3 + 3) % 3 * pw(3, i);
    a /= 3, b /= 3;
  }
  print(c);
}

int main() {
  Yorisou();
  return 0;
}