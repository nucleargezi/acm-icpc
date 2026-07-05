#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N);
  ll s = 0;
  FOR(i, 50) {
    if ((1ll << i) >= N) break;
    s += ((1ll << i) - (i ? (1ll << (i - 1)) : 0)) * (ceil(N, 1ll << i) - 1);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}