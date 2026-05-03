#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/trie_bina.hpp"

using DS = trie_bina<32, 0, uint, uint, 1 << 16>;
using np = DS::np;
void Yorisou() {
  INT(N);
  VEC(uint, a, N);
  DS g;
  np t = 0;
  for (var x : a) t = g.add(t, x);
  uint s = 0;
  for (var x : a) chmax(s, g.max(t, x));
  print(s);
}

int main() {
  Yorisou();
  return 0;
}