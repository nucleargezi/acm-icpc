#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  ll s = 0;
  FOR(i, N) FOR(k, N) FOR(j, N) s += gcd(gcd(i + 1, k + 1), j + 1);
  print(s);
}

int main() { Yorisou(); }