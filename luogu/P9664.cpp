#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"
#include "YRS/ds/un/dsu.hpp"

void Yorisou() {
  INT(N);
  sam_ex ss;
  vc<vc<int>> v(4'000'010);
  FOR(i, N) {
    STR(s);
    for (int p = 0; int c : s) p = ss.add(p, c - 'a'), v[p].ep(i);
  }
  vc<int> I(si(ss) - 1);
  iota(all(I), 1);
  sort(I, [&](int i, int k) { return ss[i].sz > ss[k].sz; });

  vc<char> vis(N, 1);
  dsu fa(N);
  Z un = [&](vc<int> &a)  {
    int n = 0;
    for (int x : a) if (vis[x = fa[x]]) vis[a[n++] = x] = 0;
    a.resize(n);
    for (int x : a) vis[x] = 1;
  };

  ll s = 0;
  for (int n : I) {
    un(v[n]);
    int sz = si(v[n]);
    FOR(i, 1, sz) fa.merge(v[n][i - 1], v[n][i]);
    if (sz) s += ss[n].sz * ll(sz - 1), v[ss[n].fa].ep(v[n][0]);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}