#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/max_subarray_sum.hpp"

using re = ld;
using MX = Max_subarr_sum<re>;
void Yorisou() {
  INT(N, Q, C);
  VEC(re, x, N);
  VEC(re, p, N - 1);
  for (Z &x : p) x /= 100;
  seg_t<MX> seg(N - 1, [&](int i) { 
    return MX::sing((x[i + 1] - x[i]) / 2 - C * p[i]); 
  });
  
  re s = 0;
  FOR(Q) {
    INT(l, r);
    --l, --r;
    s += max<re>(0, seg.prod(l, r).mx);
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}