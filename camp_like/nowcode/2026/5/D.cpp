#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/minkovski_sum.hpp"
#include "YRS/ge/basic/area.hpp"
#include "YRS/fps/base.hpp"

using mint = M99;

T lag(cf f, T c) {
  int N = si(f);
  if ((int)c.val() < N) return f[c.val()];
  Z a = f;
  FOR(i, N) {
    a[i] = a[i] * ifac(i) * ifac(N - 1 - i);
    if ((N - 1 - i) & 1) a[i] = -a[i];
  }
  vc<T> l(N + 1), r(l);
  l[0] = r[N] = 1;
  FOR(i, N) l[i + 1] = l[i] * (c - i);
  FOR_R(i, N) r[i] = r[i + 1] * (c - i);
  T s = 0;
  FOR(i, N) s += a[i] * l[i] * r[i + 1];
  return s;
}

i128 ggcd(i128 a, i128 b) {
  if (not b) return a;
  return ggcd(b, a % b);
}

mint ke(var a) {
  int N = si(a);
  mint B;
  FOR(i, N) {
    Z [x, y] = a[i] - a[(i + 1) % N];
    if (x < 0) x = -x;
    if (y < 0) y = -y; 
    B += ggcd(x, y);
  }
  mint S = invs(2) * area(a);
  mint n = S + 1 - B / 2;
  n += B;
  return n;
};

using P = point<i128>;
void Yorisou() {
  INT(N, M, Q);
  VEC(P, a, N);
  VEC(P, b, M);
  unique(a);
  unique(b);
  swap(a, b);
  a = rearrange(a, hull(a));
  b = rearrange(b, hull(b));
  for (Z &[x, y] : b) x = -x, y = -y;
  Z bb(b);
  for (Z &[x, y] : bb) x += x, y += y;
  Z bbb(b);
  for (Z &[x, y] : bbb) x += x + x, y += y + y;
  vc<mint> f(4);
  f[0] = ke(a);
  f[1] = ke(minkovski_sum(a, b));
  f[2] = ke(minkovski_sum(a, bb));
  f[3] = ke(minkovski_sum(a, bbb));
  FOR(Q) {
    LL(K);
    print(lag(f, K));
  }
}

int main() {
  Yorisou();
  return 0;
}