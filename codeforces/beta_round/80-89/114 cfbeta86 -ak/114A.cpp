#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(K, N);
  ll s = -1;
  for (; N > 1; N /= K, ++s) if (N % K) return NO();
  YES();
  print(s);
}

int main() {
  Yorisou();
  return 0;
}