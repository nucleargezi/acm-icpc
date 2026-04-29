#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/min_str.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  rotate(bg(s), bg(s) + min_str(s), ed(s));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}