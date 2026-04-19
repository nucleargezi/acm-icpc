#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  ll s = 0;
  FOR(3'000'000) {
    LL(x);
    s ^= x;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}