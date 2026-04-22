#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/chtholly/chtholly_fset.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  chtholly_fset<int> g(N, 0);
  FOR(i, N) g.set(i, i + 1, a[i]);
  
  FOR(N) {
    INT(l, r, x);
    --l;
    int s = 0;
    for (var [l, r, c] : g.get(l, r)) if (c == x) s += r - l;
    g.set(l, r, x);
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}