#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/seg/segl_t.hpp"
#include "YRS/al/am/presum_add.hpp"

using mint = M17;
using MX = Presum_add<mint, 3>;

void Yorisou() {
  INT(N, Q);
  int c = (N + 1) >> 1;
  vc<mint> a(c);
  FOR(i, N) {
    LL(x);
    a[min(i, N - 1 - i)] += x;
  }
  segl_t<MX> seg(c, [&](int i) { return MX::X(i, a[i]); });

  Z f = [&](int t) -> mint {
    if (t == 0) return 0;
    Z x = seg.prod(0, t - 1);
    mint s = seg.prod().s[0];
    return x.s[0] * t + x.s[1] * (t - 1) - x.s[2] +
           (s - x.s[0]) * mint(t) * (t + 1) / 2;
  };

  FOR(Q) {
    INT(op, l, r);
    if (op == 1) {
      LL(d);
      if (l > r) swap(l, r);
      --l;
      if (l < c) seg.apply(l, min(r, c), d);
      if (r > c) seg.apply(N - r, N - max(l, c), d);
    } else {
      mint s = 0;
      if (l <= c) s += f(min(r, c)) - f(l - 1);
      if (r > c) {
        int L = max(l, c + 1);
        s += f(N - L + 1) - f(N - r);
      }
      print(s);
    }
  }
}

int main() { Yorisou(); }