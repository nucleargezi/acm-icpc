#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/sp.hpp"

void Yorisou() {
  INT(N);
  sp<ll> a;
  FOR(N) {
    LL(x);
    a.add(x);
  }
  print(a.max());
}

int main() {
  Yorisou();
  return 0;
}