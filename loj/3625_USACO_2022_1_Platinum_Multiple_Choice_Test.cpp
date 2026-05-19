#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/minkovski_sum.hpp"

using P = point<ll>;
void Yorisou() {
  INT(N);
  vc<vc<P>> a;
  FOR(i, N) {
    INT(sz);
    VEC(P, h, sz);
    a.ep(rearrange(h, hull(h)));
  }
  Z f = [&](Z &f, int l, int r) -> vc<P> {
    if (l + 1 == r) return a[l];
    int m = (l + r) >> 1;
    return minkovski_sum(f(f, l, m), f(f, m, r));
  };
  ll s = 0;
  for (var x : f(f, 0, N)) chmax(s, x.sq());
  print(s);
}

int main() {
  Yorisou();
  return 0;
}