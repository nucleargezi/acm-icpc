#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  STR(a, b);
  for (char &c : a) c = tolower(c);
  for (char &c : b) c = tolower(c);
  print(a == b ? 0 : a < b ? -1 : 1);
}

int main() {
  Yorisou();
  return 0;
}