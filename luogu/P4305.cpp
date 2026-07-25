#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<ll> s;
  set<ll> se;
  FOR(N) {
    LL(x);
    if (se.eb(x).se) s.ep(x);
  }
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}