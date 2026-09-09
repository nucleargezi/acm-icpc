#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  string s[2];
  int a[2];
  IN(s[0], s[1], a[0], a[1]);
  STR(f);
  FOR(i, 2) if (s[i] == f) a[i] -= 1;
  print(a[0], a[1]);
}

int main() { Yorisou(); }