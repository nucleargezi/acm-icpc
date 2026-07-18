#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/runs.hpp"

void Yorisou() {
  STR(s);
  Z rs = runs(s);
  print(si(rs));
  for (var [l, r ,p] : rs) print(l + 1, r, p);
}

int main() {
  Yorisou();
  return 0;
}