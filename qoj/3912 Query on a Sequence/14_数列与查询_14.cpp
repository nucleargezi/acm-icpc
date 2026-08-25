#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/wave/sswave_dist.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  sswave_dist g(a);
  INT(Q);
  int ls = 0;
  FOR(Q) {
    INT(a, b, c, d, k);
    --k;
    int l = (1ll * a * max(ls, 0) + b) % N;
    int r = (1ll * c * max(ls, 0) + d) % N;
    if (l > r) swap(l, r);
    ++r;
    if (g.size(l, r) <= k) print(ls = -1);
    else print(ls = f[g.kth(l, r, k)]);
  }
}

int main() {
  Yorisou();
  return 0;
}