#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/kmp.hpp"

void Yorisou() {
  STR(s);
  Z rs = get_next(s).fi;
  rs.erase(bg(rs));
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}