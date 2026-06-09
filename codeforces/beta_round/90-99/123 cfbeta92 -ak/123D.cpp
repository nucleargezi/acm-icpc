#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  int N = si(s);
  FOR(i, N) s[i] -= 'a';
  sam<26> sa(N);
  vc<int> sz = sa.build(s);
  N = si(sa);
  ll rs = 0;
  FOR(i, 1, N) {
    ll c = sa[i].sz - sa[sa[i].fa].sz, f = sz[i];
    rs += f * (f + 1) / 2 * c;
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}