#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N, K, M);
  VEC(string, s, N);
  VEC(int, c, N);
  map<string, int> mp;
  FOR(i, N) mp[s[i]] = i;

  dsu g(N);
  FOR(K) {
    INT(sz);
    VEC(int, s, sz);
    for (int &x : s) --x;
    FOR(i, sz - 1) {
      int a = s[i], b = s[i + 1];
      a = g[a], b = g[b];
      g.merge(a, b);
      int f = g[a];
      if (c[a] < c[b]) c[f] = c[a];
      else c[f] = c[b];
    }
  }

  ll rs = 0;
  FOR(M) {
    STR(s);
    rs += c[g[mp[s]]];
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}