#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  int n = si(s);
  FOR(i, n - 1) if (s[i] == s[i + 1]) return print(n - 1);
  print(n - 2);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}