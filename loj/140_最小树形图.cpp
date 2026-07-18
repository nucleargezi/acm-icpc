#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dmst.hpp"

void Yorisou() {
  INT(N, M, s);
  --s;
  VEC(T3<int>, es, M);
  for (Z &[a, b, c] : es) --a, --b;
  Z rs = dmst<ll>(N, s, es);
  if (rs) print(*rs);
  else print(-1);
}

int main() {
  Yorisou();
  return 0;
}