#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(a, b);
  string sa = to_string(a), sb = to_string(b), l, r;
  FOR(a) l += sb;
  FOR(b) r += sa;
  print(min(l, r));
}

int main() { Yorisou(); }