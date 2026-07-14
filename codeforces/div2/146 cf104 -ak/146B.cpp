#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b);
  FOR(i, a + 1, 1919810) {
    string s(to_string(i)), t;
    for (char c : s) if (c == '4' or c == '7') t += c;
    if (t == to_string(b)) return print(i);
  }
}

int main() {
  Yorisou();
  return 0;
}