#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/lyndon.hpp"

void Yorisou() {
  STR(s);
  print(lyndon(s));
}

int main() {
  Yorisou();
  return 0;
}