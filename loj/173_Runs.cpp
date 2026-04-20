#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/runs.hpp"

void Yorisou() {
  STR(s);
  Z rs = runs(s);
  print(si(rs));
  for (var [a, b, c] : rs) print(a + 1, b, c);
}

int main() {
  Yorisou();
  return 0;
}