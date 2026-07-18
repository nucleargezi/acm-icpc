#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  sam g(N << 1);
  FOR(i, N) s[i] -= 'a';
  Z sz = g.build(s);
  ll rs = 0;
  N = si(g);
  FOR(i, N) if (sz[i] != 1) chmax(rs, 1ll * g[i].sz * sz[i]);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}