#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/pam.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  FOR(i, N) s[i] -= 'a';
  pam<26> g(s);
  N = si(g.a);
  vc<int> fa(N, -1);
  FOR(i, N) for (int x : g.a[i].to) if (x != -1) fa[x] = i;
  print(N - 2);
  FOR(i, 2, N) print(fa[i] - 1, g.a[i].lk - 1);
  vc<int> pa{bg(g.pa) + 1, ed(g.pa)};
  for (int &x : pa) --x;
  print(pa);
}

int main() {
  Yorisou();
  return 0;
}