#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  vc<int> sz = ss.build(s);
  vc<ll> rs(si(s));
  FOR(i, 1, si(ss)) rs[sz[i] - 1] += ss[i].sz - ss[ss[i].fa].sz;
  for (ll x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}