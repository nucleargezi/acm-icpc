#include "YRS/all.hpp"

void Yorisou() {
  FOR(i, 1000) {
    string s = to_string(i);
    while (si(s) < 3) s = "0" + s;
    print(s);
    IN(s);
    if (s == "unlocked") break;
  }
}

int main() {
  Yorisou();
  return 0;
}