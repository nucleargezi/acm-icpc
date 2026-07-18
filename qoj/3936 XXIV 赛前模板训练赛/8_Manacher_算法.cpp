#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/manacher.hpp"

void Yorisou() {
  STR(s);
  int rs = 0;
  for (var [l, r] : manacher(s)) chmax(rs, r - l);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}