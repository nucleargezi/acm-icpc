#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/flow/flow_lm.hpp"

void Yorisou() {
  INT(N, M);
  flow_lm<int> g(N, 0, 0);
  FOR(M) {
    INT(f, t, l, r);
    --f, --t;
    g.add(f, t, l, r);
  }
  g.build();
  Z [ok, f] = g.check();
  if (ok) {
    print("YES");
    for (Z &&e : g.get_flow_es()) print(get<2>(e));
  } else {
    print("NO");
  }
}

int main() {
  Yorisou();
  return 0;
}