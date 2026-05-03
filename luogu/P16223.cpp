#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  print(furthest_pair(a));
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}