#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/mo/mo.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l;

  int n = QMAX(a) + 1;
  bit_t<Add<ll>> bit(n);
  ll s = 0;
  Z ad = [&](int i) {
    int x = a[i];
    s += bit.prod(max(0, x - K), min(x + K + 1, n));
    bit.add(x, 1);
  };
  Z rm = [&](int i) {
    int x = a[i];
    bit.add(x, -1);
    s -= bit.prod(max(0, x - K), min(x + K + 1, n));
  };

  vc<ll> rs(Q);
  Mo mo(q);
  mo.f(ad, ad, rm, rm, [&](int i) { rs[i] = s; });
  for (ll x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}