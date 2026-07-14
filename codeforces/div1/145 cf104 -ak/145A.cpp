#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s, t);
  int a = 0, b = 0, n = si(s);
  FOR(i, n) if (s[i] != t[i]) (s[i] == '4' ? a : b) += 1;
  print(max(a, b));
}

int main() {
  Yorisou();
  return 0;
}