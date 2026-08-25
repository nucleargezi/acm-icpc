#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/bit/bit.hpp"
#include "YRS/al/m/add.hpp"
#include "YRS/ds/mo/mo.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  VEC(int, b, N);
  INT(Q);
  vc<PII> q(Q);
  vc<int> K(Q);
  FOR(i, Q) {
    INT(a, b, c);
    --a;
    q[i] = {a, b};
    K[i] = c;
  }
  Mo mo(q);
  vc<int> ca(114514), cb(ca);
  bit_t<Add<ll>> ta(114514), tb(ta);
  Z ad = [&](int i) {
    int x = a[i];
    ca[x] += 1;
    ta.add(x, 1);
    x = b[i];
    cb[x] += 1;
    tb.add(x, 1);
  };
  Z rm = [&](int i) {
    int x = a[i];
    ca[x] += -1;
    ta.add(x, -1);
    x = b[i];
    cb[x] += -1;
    tb.add(x, -1);
  };
  vc<ll> rs(Q);
  Z ke = [&](int i) {
    int k = K[i], s = (int)sqrtl(k) + 1;
    while (1ll * s * s > k) --s;
    ll w = 0, sb = tb.prod(s + 1);
    FOR(x, 1, s + 1) {
      int y = k / x;
      if (cb[x]) w += 1ll * cb[x] * ta.prod(y + 1);
      if (ca[x]) w += 1ll * ca[x] * (tb.prod(y + 1) - sb);
    }
    rs[i] = w;
  };
  mo.f(ad, ad, rm, rm, ke);
  for (ll x : rs) print(x);
}

int main() {
  Yorisou();
  return 0;
}