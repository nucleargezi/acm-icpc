#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/string/sam_ex.hpp"

void Yorisou() {
  INT(N);
  sam_ex g;
  FOR(N) {
    STR(s);
    for (int p = 0; int x : s) p = g.add(p, x - 'a');
  }
  ll s = 0;
  N = si(g);
  FOR(i, 1, N) s += g[i].sz - g[g[i].fa].sz;
  print(s);
}

int main() {
  Yorisou();
  return 0;
}