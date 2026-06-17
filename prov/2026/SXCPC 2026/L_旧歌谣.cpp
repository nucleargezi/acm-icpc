#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(x);
  ll s = 1, t = 1;
  string str = to_string(x);
  int n = si(str);
  FOR(n - 1) s *= 10;
  s = x % s + 1;
  FOR(n - 1 - (str[0] == '1')) t *= 10;
  s += t;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}