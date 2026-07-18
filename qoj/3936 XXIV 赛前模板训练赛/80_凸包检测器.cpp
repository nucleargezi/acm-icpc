#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/ge/basic/convex_checker.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  Yes(convex_checker(a));
}

int main() {
  Yorisou();
  return 0;
}