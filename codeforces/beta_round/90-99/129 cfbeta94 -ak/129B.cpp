#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<int>> g(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    g[a].ep(b);
    g[b].ep(a);
  }
  
  FOR(i, N + 1) {
    vc<int> st;
    FOR(i, N) if (si(g[i]) == 1) st.ep(i);
    for (int n : st) {
      for (int x : g[n]) g[x].erase(find(all(g[x]), n));
      g[n].clear();
    }
    if (st.empty()) return print(i);
  }
}

int main() {
  Yorisou();
  return 0;
}