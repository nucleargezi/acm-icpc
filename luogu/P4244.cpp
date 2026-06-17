#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/cactus/diameter.hpp"

void Yorisou() {
  INT(N, r);
  vc<vc<edge_id_w<int>>> g(N);
  vc<int> p;
  p.reserve(N);
  int ei = 0;
  FOR(r) {
    INT(sz);
    sh(p, sz);
    for (int &x : p) IN(x), --x;
    FOR(i, sz - 1) {
      int a = p[i], b = p[i + 1];
      g[a].ep(b, ei, 1);
      g[b].ep(a, ei, 1);
      ++ei;
    }
  }
  print(cactus_diameter<int>(g));
}

int main() {
  Yorisou();
  return 0;
}