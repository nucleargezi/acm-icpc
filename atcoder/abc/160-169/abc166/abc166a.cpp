#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(s);
  s[1] = s[1] == 'B' ? 'R' : 'B';
  print(s);
}

int main() { Yorisou(); }