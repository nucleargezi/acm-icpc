#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N, D, A);
  VEC(PII, dat, N);
  sort(dat);
  vc<PII> b;
  for (var [x, n] : dat) {
    if (b.empty() or b.back().fi != x) b.ep(x, n);
    else b.back().se = n;
  }
  dat.swap(b);
  min_heap<PLL> q;
  ll f = 0, s = 0;
  for (var [x, n] : dat) {
    while (si(q) and q.top().fi < x) f -= pop(q).se;
    if (f < n) {
      ll d = ceil<ll>(n - f, A);
      q.eb(x + D + D, d * A);
      s += d, f += d * A;
    }
  }
  print(s);
}

int main() { Yorisou(); }