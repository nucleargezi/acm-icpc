#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  reverse(s);
  for (char &c : s) c -= 'a';
  sam ss;
  Z [sz, V] = ss.slv(s);
  int N = si(s);
  ll rs = ll(N - 1) * N * (N + 1) / 2;
  reverse(V);
  pop(V);
  vc<int> f(si(ss));
  for (int x : ss.en) f[x] = 1;
  for (int n : V) {
    int fa = ss[n].fa;
    rs -= ll(sz[n]) * f[fa] * ss[fa].sz * 2;
    f[fa] += sz[n];
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}