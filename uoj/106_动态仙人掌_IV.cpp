#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/top_cactus.hpp"
#include "YRS/al/am/minsum_add.hpp"

void Yorisou() {
  INT(N, Q);
  vc<PLL> a(N);
  FOR(i, N) IN(a[i].fi), a[i].se = a[i].fi;
  top_cactus<Minsum_add<ll>> g(a, Q);

  FOR(i, Q) {
    STR(op);
    INT(a, b);
    --a, --b;
    if (op[0] == 'l') {
      INT(c);
      print(g.link(a, b, c) ? "ok" : "failed");
    } else if (op[0] == 'c') {
      INT(c);
      print(g.cut(a, b, c) ? "ok" : "failed");
    } else if (op == "query1") {
      Z [e, s] = g.prod_path(a, b);
      if (e) print(e, e);
      else print(s);
    } else if (op == "query2") {
      Z [e, s] = g.prod_sub(a, b);
      if (e) print(e, e);
      else print(s);
    } else if (op == "add1") {
      INT(c);
      print(g.apply_path(a, b, c) ? "failed" : "ok");
    } else {
      INT(c);
      print(g.apply_sub(a, b, c) ? "ok" : "failed");
    }
  }
}

int main() {
  Yorisou();
  return 0;
}