#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f = a;
  for (int x : a) f.ep(x - 1), f.ep(x + 1);
  unique(f);
  for (int &x : a) x = lb(f, x);
  N = QMAX(a) + 1;
  vc<int> c(N);
  for (int x : a) ++c[x];

  int l = N, r = -1;
  FOR(i, N) if (c[i]) r = i;
  FOR_R(i, N) if (c[i]) l = i;
  if (QMAX(c) == 1 and r - l != 1) return NO();
  FOR(i, l, r + 1) if (c[i] == 0) return NO();

  int cnt = 0;
  vc<int> buf;
  FOR(i, l, r + 1) {
    if (c[i] == 1) {
      if (si(buf)) ++cnt;
      buf.clear();
    } else {
      buf.ep(c[i]);
    }
  }
  if (si(buf)) ++cnt;
  if (cnt == 1) {
    int ls = 0;
    FOR(i, l, r + 1) {
      if (ls) c[i] -= ls;
      if (c[i] < 0) return NO();
      ls = c[i];
    }
    NO(ls);
  } else {
    NO();
  }
}

int main() {
  Yorisou();
  return 0;
}