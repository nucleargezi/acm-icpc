#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  ll s = 0;
  FOR(i, N) {
    LL(x);
    s += i * (x - 1) + x;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}