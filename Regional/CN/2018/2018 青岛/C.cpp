#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/graph/Apck/bfs.hpp"

#define tests
constexpr int M = 256;
int id(int x, int y) { return x * M + y; }
void Yorisou() {
  INT(N);
  graph<int, true> g((N + 1) * M);
  FOR(i, N) {
    STR(op);
    if (op == "add") {
      INT(a);
      FOR(k, M) g.add(id(i, k), id(i + 1, (k + a) % M));
    } else if (op == "beq") {
      INT(a, tp);
      --tp;
      FOR(k, M) {
        if (k == a) g.add(id(i, k), id(tp, k));
        else g.add(id(i, k), id(i + 1, k));
      }
    } else if (op == "bne") {
      INT(a, tp);
      --tp;
      FOR(k, M) {
        if (k != a) g.add(id(i, k), id(tp, k));
        else g.add(id(i, k), id(i + 1, k));
      }
    } else if (op == "blt") {
      INT(a, tp);
      --tp;
      FOR(k, a) g.add(id(i, k), id(tp, k));
      FOR(k, a, M) g.add(id(i, k), id(i + 1, k));
    } else if (op == "bgt") {
      INT(a, tp);
      --tp;
      FOR(k, a + 1, M) g.add(id(i, k), id(tp, k));
      FOR(k, a + 1) g.add(id(i, k), id(i + 1, k));
    }
  }
  g.build();
  bool ok = false;
  Z dis = bfs(g, 0).fi;
  FOR(i, M) ok |= dis[id(N, i)] != inf<int>;
  Yes(ok);
}
#include "YRS/Z_H/main.hpp"