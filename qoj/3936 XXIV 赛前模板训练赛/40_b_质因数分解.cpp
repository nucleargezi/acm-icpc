#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  INT(Q);
  vc<ll> s;
  FOR(Q) {
    s.clear();
    LL(x);
    for (var [a, b] : factor(x)) FOR(b) s.ep(a);
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}