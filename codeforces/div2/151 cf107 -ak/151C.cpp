#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/divisors.hpp"

void Yorisou() {
  LL(N);
  if (N == 1 or ptest(N)) return print(1), print(0); 
  for (ll x : divisor(N)) if (x != N and x != 1) {
    if (not ptest(x)) return print(1), print(x);
  }
  print(2);
}

int main() {
  Yorisou();
  return 0;
}