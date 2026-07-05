#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/run_length.hpp"

void Yorisou() {
  STR(s);
  int rs = 0;
  for (var [a, b] : run_length(s)) rs += ceil(b, 5);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}