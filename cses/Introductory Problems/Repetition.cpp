#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/run_length.hpp"

void Yorisou() {
  STR(s);
  int x = 0;
  for (var [a, b] : run_length(s)) chmax(x, b);
  print(x);
}

int main() {
  Yorisou();
  return 0;
}