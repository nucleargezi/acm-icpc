#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/factors.hpp"
#include "YRS/ds/un/nxt_dsu.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  constexpr int sz = 1504'840;
  vc<int> rs(N), lpf(lpf_table(sz));
  vc<char> ban(sz);
  nxt_dsu se(sz);

  Z slv = [&](int x) {
    for (Z [e, p] : factor(x, lpf)) {
      if (not ban[e]) {
        ban[e] = 1;
        FOR(i, e, sz, e) if (se[i] == i) se.del(i);
      }
    }
  };
  
  bool f = 0;
  FOR(i, N) {
    int x = f ? 2 : a[i];
    if (se[x] != x) f = 1;
    slv(rs[i] = se[x]);
  }
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}