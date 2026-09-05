#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/IO/yn.hpp"
#include "YRS/gg/euler_walk.hpp"

void Yorisou() {
  INT(op);
  if (op == 1) {
    INT(N, M);
    vc<vc<edge_id>> g(N);
    vc<PII> es(M);
    FOR(i, M) {
      INT(a, b);
      --a, --b;
      es[i] = {a, b};
      g[a].ep(b, i), g[b].ep(a, i);
    }
    Z vs = euler_walk_undir(g);
    if (si(vs) - 1 == M and vs[0] == vs.back()) {
      YES();
      Z ei = vs_es(g, vs, 0);
      FOR(i, si(ei)) {
        int f = vs[i], &id = ei[i];
        if (es[id].fi == f) ++id;
        else id = -id - 1;
      }
      print(ei);
    } else NO();
  } else {
    INT(N, M);
    vc<vc<edge_id>> g(N);
    FOR(i, M) {
      INT(a, b);
      --a, --b;
      g[a].ep(b, i);
    }
    Z vs =  euler_walk_dir(g);
    if (si(vs) - 1 == M and vs[0] == vs.back()) {
      Z ei = vs_es(g, vs, 1);
      YES();
      for (int &x : ei) ++x;
      print(ei);
    } else NO();
  }
}

int main() { Yorisou(); }