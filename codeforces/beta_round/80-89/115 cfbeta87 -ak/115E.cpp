#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/max_add.hpp"

void Yorisou() {
  INT(N, M);
  VEC(int, a, N);
  vc<vc<PII>> v(N);
  FOR(M) {
    INT(l, r, x);
    --l, --r;
    v[r].ep(r - l, x);
  }
  
  segl_t<Max_add<ll>> seg(vc<ll>(N + N, -inf<ll> / 2));
  int bs = N;
  seg.set(bs, 0);
  FOR(i, N) {
    seg.set(bs - 1, seg.prod(bs, bs + N));
    seg.apply(bs, bs + N, -a[i]);
    for (var [sz, w] : v[i]) seg.apply(bs + sz, bs + N, w);
    --bs;
  }
  print(seg.prod());
}

int main() {
  Yorisou();
  return 0;
}