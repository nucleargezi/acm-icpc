#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"
#include "YRS/ds/mo/mo.hpp"

using mint = M99;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  for (int &x : a) --x;
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;
  vc<int> c(N);
  mint x, xx;
  vc<mint> rs(Q);
  Z ad = [&](int i) {
    int &g = c[a[i]];
    x -= g;
    xx -= mint(g) * g;
    ++g;
    x += g;
    xx += mint(g) * g;
  };
  Z sb = [&](int i) {
    int &g = c[a[i]];
    x -= g;
    xx -= mint(g) * g;
    --g;
    x += g;
    xx += mint(g) * g;
  };
  Z ke = [&](int i) {
    var [l, r] = q[i];
    mint s = (x * (r - l) - xx) / (r - l) + 1;
    rs[i] = s;
  };
  Mo mo(Q);
  for (var [l, r] : q) mo.add(l, r);
  mo.f(ad, ad, sb, sb, ke);
  for (mint x : rs) print(x);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}