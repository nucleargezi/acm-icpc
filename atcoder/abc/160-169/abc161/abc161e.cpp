#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K, c);
  STR(s);
  vc<int> f, g;
  int pr = -1;
  FOR(i, N) if (s[i] == 'o' and pr < i) f.ep(i), pr = i + c;
  pr = N + c;
  FOR_R(i, N) if (s[i] == 'o' and i + c < pr) g.ep(i), pr = i;
  if (si(f) > K) return;
  reverse(g);
  FOR(i, K) if (f[i] == g[i]) print(f[i] + 1);
}

int main() { Yorisou(); }