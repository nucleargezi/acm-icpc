#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  bool f = 1;
  FOR(i, 1, si(s)) {
    f &= s[i] >= 'A' and s[i] <= 'Z';
  }
  if (f) {
    for (char &c : s) {
      if (c >= 'a' and c <= 'z') c += 'A' - 'a';
      else c += 'a' - 'A';
    }
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}