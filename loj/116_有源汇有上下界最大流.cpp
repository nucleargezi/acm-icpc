#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flow_lm.hpp"

void Yorisou() {
  INT(N, M, s, t);
  --s, --t;
  flow_lm<int> g(N, s, t);
  FOR(M) {
    INT(f, t, l, r);
    --f, --t;
    g.add(f, t, l, r);
  }
  g.build();
  Z [a, b] = g.qmax();
  if (a) print(b);
  else print("please go home to sleep");
}

int main() {
  Yorisou();
  return 0;
}