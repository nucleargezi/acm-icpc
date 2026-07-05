#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/gg/find_min_cost_C.hpp"

void Yorisou() {
  INT(N, M);
  vc<vc<edge_id_w<int>>> g(N);
  map<PII, int> mp;
  FOR(i, M) {
    INT(a, b, c);
    --a, --b;
    if (a > b) swap(a, b);
    if (not mp.contains({a, b})) mp[{a, b}] = c;
    else chmin(mp[{a, b}], c);
  }
  for (int i = 0; var [e, c] : mp) {
    var [a, b] = e;
    g[a].ep(b, i, c);
    g[b].ep(a, i, c);
    ++i;
  }
  int s = get<0>(find_min_cost_C_undir<int>(g));
  if (s == inf<int>) print("No solution.");
  else print(s);
}

int main() {
  Yorisou();
  return 0;
}