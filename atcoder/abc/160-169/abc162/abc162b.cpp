#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  ll s = 0;
  FOR(i, 1, N + 1) if (i % 3 and i % 5) s += i;
  print(s);
}

int main() { Yorisou(); }