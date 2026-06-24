#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_map.hpp"
#include "YRS/ds/un/nxt_dsu.hpp"

void Yorisou() {
  INT(sig, N);
  vc<int> s(N);
  if (sig != 26) {
    IN(s);
  } else {
    STR(str);
    FOR(i, N) s[i] = str[i] - 'a';
  }
  sam_map ss(N);
  reverse(s);
  vc<int> V = ss.slv(s).se;
  reverse(s);
  int M = si(ss);

  vc<int> mn(M, inf<int>);
  FOR(i, N) chmin(mn[ss.en[i]], N - i - 1);
  FOR_R(i, 1, M) {
    int n = V[i];
    chmin(mn[ss[n].fa], mn[n]);
  }
  vc<vc<int>> g(M);
  FOR(i, 1, M) g[ss[i].fa].ep(i);

  FOR(n, M) {
    sort(g[n], [&](int a, int b) {
      int l = s[mn[a] + ss[n].sz], r = s[mn[b] + ss[n].sz];
      return l == r ? mn[a] < mn[b] : l < r;
    });
  }
  vc<int> rs(N);
  nxt_dsu f(N + 1);
  vc<PII> st;
  FOR_R(i, si(g[0])) st.ep(0, g[0][i]);
  while (si(st)) {
    Z [p, n] = pop(st);
    int l = ss[p].sz + 1, r = ss[n].sz;
    for (int k = f[l]; k <= r; k = f[k]) {
      rs[k - 1] = mn[n] + 1;
      f.del(k);
    }
    FOR_R(i, si(g[n])) st.ep(n, g[n][i]);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}