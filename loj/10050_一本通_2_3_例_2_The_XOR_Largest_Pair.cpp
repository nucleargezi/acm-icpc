#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/trie_bina.hpp"

using DS = trie_bina<31, 0, int, int, 1 << 16>;
using np = DS::np;
void Yorisou() {
  DS g;
  np t = 0;
  INT(N);
  int s = 0;
  FOR(i, N) {
    INT(x);
    if (i) chmax(s, g.max(t, x));
    t = g.add(t, x);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}