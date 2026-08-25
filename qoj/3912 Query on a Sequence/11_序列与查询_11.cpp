#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/mo/mo.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  a.insert(bg(a), 0);
  ++N;
  FOR(i, 1, N) a[i] ^= a[i - 1]; 
  vc<int> c(1 << 21);
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l, ++r;
  Mo mo(q);
  ll s = 0;
  Z ad = [&](int x) {
    x = a[x];
    s += c[x ^ K];
    ++c[x];
  };
  Z rm = [&](int x) {
    x = a[x];
    --c[x];
    s -= c[x ^ K];
  };
  vc<ll> rs(Q);
  mo.f(ad, ad, rm, rm, [&](int i) { return rs[i] = s; });
  for (ll s : rs) print(s);
}

int main() {
  Yorisou();
  return 0;
}