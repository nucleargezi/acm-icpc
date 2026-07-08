#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"

void Yorisou() {
  STR(a, b, c);
  a += b;
  multiset<char> A(all(a)), B(all(c));
  YES(A == B);
}

int main() {
  Yorisou();
  return 0;
}