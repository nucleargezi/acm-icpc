#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam.hpp"

void Yorisou() {
  STR(s);
  INT(K);
  for (char &c : s) c -= 'a';
  sam ss(si(s));
  vc<int> sz = ss.build(s);
  int N = si(s), M = si(ss);
  vc<ll> c(N + 2);
  FOR(n, 1, M) if (sz[n] == K) {
    int l = ss[ss[n].fa].sz + 1, r = ss[n].sz + 1;
    c[l] += 1, c[r] -= 1;
  }
  FOR(i, N + 1) c[i + 1] += c[i];
  int mx = 0, rs = -1;
  FOR_R(i, N + 1) if (chmax(mx, c[i])) rs = i;
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}