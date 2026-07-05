#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/seg_dual_t.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/al/m/xor.hpp"
#include "YRS/al/m/sp.hpp"

using bs = sp<int>;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<int> b(N);
  FOR(i, 1, N) b[i] = a[i] ^ a[i - 1];
  seg_dual_t<Xor<int>> s(N);
  seg_t<Sp<int>> seg(N, [&](int i) {
    bs x;
    x.add(b[i]);
    return x;
  });

  FOR(Q) {
    INT(op, l, r, x);
    --l;
    if (op == 1) {
      s.apply(l, r, x);
      bs nx;
      nx.add(b[l] ^= x);
      seg.set(l, nx);
      nx.a.clear();
      if (r != N) nx.add(b[r] ^= x), seg.set(r, nx);
    } else {
      bs e = l == r ? bs() : seg.prod(l + 1, r);
      e.add(s.get(l) ^ a[l]);
      print(e.max(x));
    }
  }
}

int main() {
  Yorisou();
  return 0;
}