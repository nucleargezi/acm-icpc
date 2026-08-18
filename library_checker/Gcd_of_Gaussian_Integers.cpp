#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/gaussian_gcd.hpp"

void Yorisou() {
  INT(Q);
  PLL a, b;
  FOR(Q) {
    IN(a, b);
    print(gaussian_gcd(a, b));
  }
}

int main() {
  Yorisou();
  return 0;
}