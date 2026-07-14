#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/dmst.hpp"

void Yorisou() {
  INT(N, M, s);
  --s;
  VEC(T3<int>, es, M);
  for (Z &[f, t, w] : es) --f, --t;
  Z rs = dmst<int>(N, s, es);
  print(rs ? *rs : -1);
}

int main() {
  Yorisou();
  return 0;
}