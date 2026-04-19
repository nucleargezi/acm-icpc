#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/lyndon.hpp"

void Yorisou() {
  STR(s);
  Z t = lyndon(s);
  t.erase(bg(t));
  print(t);
}

int main() {
  Yorisou();
  return 0;
}