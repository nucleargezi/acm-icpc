#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ttr/subtree_hash.hpp"

ull gen(int N) {
  vc<vc<int>> g(N);
  FOR(N - 1) {
    INT(a, b);
    --a, --b;
    g[a].ep(b), g[b].ep(a);
  }
  return tree_hash(g)[0];
}

void Yorisou() {
  INT(N);
  Z a(gen(N)), b(gen(N));
  if (a == b) print("Isomorphism");
  else print("No");
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}
