#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  if (QMAX(s) == QMIN(s)) return print(ll(N + 2) * (N - 1));
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  ss.build(s);
  print(ss.count() - 2 + ll(N + 1) * N / 2);
}

int main() {
  Yorisou();
  return 0;
}