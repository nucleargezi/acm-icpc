#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/zfunction.hpp"

void Yorisou() {
  STR(s);
  Z rs = z_function(s);
  rs[0] = 0;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}