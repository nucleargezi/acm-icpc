#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/enum_div.hpp"

void Yorisou() {
  LL(N);
  vc<ll> s = enum_div(N);
  print(si(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}