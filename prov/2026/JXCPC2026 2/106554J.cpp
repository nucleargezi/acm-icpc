#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/angle_sort.hpp"
#include "YRS/ds/st/range_max.hpp"

using re = ld;
using P = point<ll>;
void Yorisou() {
  INT(N, K);
  VEC(P, a, N);
  a = rearrange(a, angle_sort(a));
  FOR(i, N) a.ep(a[i]);
  vc<ll> dat(N + N);
  FOR(i, N + N) dat[i] = a[i].sq();
  range_max<ll, 0> st(dat);

  for (Z &[x, y] : a) {
    ll g = gcd(x, y);
    x /= g, y /= g;
  }
  vc<int> l(N + N), r(l);
  FOR(i, 1, N + N) {
    if (a[i] == a[i - 1]) l[i] = l[i - 1];
    else l[i] = i;
  }
  r.back() = N + N - 1;
  FOR_R(i, N + N - 1) {
    if (a[i] == a[i + 1]) r[i] = r[i + 1];
    else r[i] = i;
  }
  
  re s = inf<re>;
  FOR(i, N) {
    int L = l[i], R = r[i + K - 1];
    P f = a[L], t = a[R];
    re an = P::angle(f, {0, 0}, t);
    if (ccw(f, P{0, 0}, t) == 1) an = 2 * pi - an;
    if (a[L] == a[R] and r[L] < R) an = pi * 2;
    chmin(s, st.prod(L, R + 1) * an);
  }
  print(s / 2);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}