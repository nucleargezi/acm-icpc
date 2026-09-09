#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  STR(s);
  if (N < si(s)) s.resize(N), s += "...";
  print(s);
}

int main() { Yorisou(); }