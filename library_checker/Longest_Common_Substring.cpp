#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/lcs.hpp"

void Yorisou() {
  STR(s, t);
  Z [a, b, c, d] = lcs(s, t);
  print(a, b, c, d);
}

int main() {
  Yorisou();
  return 0;
}