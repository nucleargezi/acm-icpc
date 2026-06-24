#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/SA/lev_dist.hpp"

void Yorisou() {
  INT(K);
  STR(s, t);
  print(SUM<int>(lev_dist({all(s)}, {all(t)}, K)));
}

int main() {
  Yorisou();
  return 0;
}