#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/manacher.hpp"

void Yorisou() {
  STR(s);
  print(manacher_len(s));
}

int main() {
  Yorisou();
  return 0;
}