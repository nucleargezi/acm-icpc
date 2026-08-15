#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/sp.hpp"

void Yorisou() {
  sp<ll> s;
  INT(Q);
  FOR(Q) {
    LL(x);
    s.ins(x);
  }
  print(s.max());
}

int main() {
  Yorisou();
  return 0;
}