#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/dwave.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  dwave<18> g(a);
  ll s = 0;
  FOR(i, N - 1) s += g.rank(i + 1, N, a[i]);
  print(s);

  Z go = [&](int i) {
    int x = a[i];
    return i - g.rank(0, i, x + 1) + g.rank(i + 1, N, x);
  };
  INT(Q);
  FOR(Q) {
    INT(i, k);
    --i, --k;
    int l = a[i], r = a[k];
    s -= go(i);
    a[i] = r;
    g.set(i, r);
    s += go(i);
    s -= go(k);
    a[k] = l;
    g.set(k, l);
    s += go(k);
    print(s);
  }
}

int main() {
  Yorisou();
  return 0;
}