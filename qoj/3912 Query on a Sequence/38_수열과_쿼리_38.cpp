#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  ll s = 0, ss = 0;
  FOR(N) {
    INT(op);
    if (op == 1) {
      INT(x);
      s += x;
      ss ^= x;
    } else if (op == 2) {
      INT(x);
      s -= x;
      ss ^= x;
    } else if (op == 3) {
      print(s);
    } else {
      print(ss);
    }
  }
}

int main() {
  Yorisou();
  return 0;
}