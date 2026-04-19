#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  LL(x);
  vc<ll> s;
  for (var [a, b] : factor(x)) FOR(b) s.ep(a);
  print(si(s), s);
}

int main() {
  INT(T); 
  FOR(T) Yorisou();
  return 0;
}