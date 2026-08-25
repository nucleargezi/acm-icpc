#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/mo/mo_roll.hpp"
#include "YRS/ds/rb/rb_arr.hpp"

void Yorisou() {
  INT(N, K);
  vc<int> a(N + 1);
  FOR(i, 1, N + 1) IN(a[i]), a[i] = (a[i - 1] + a[i]) % K;
  Z f(a);
  unique(f);
  for (int &x : a) x = lb(f, x);
  INT(Q);
  VEC(PII, q, Q);
  for (Z &[l, r] : q) --l, ++r;
  // vc<PII> dat(si(f), {inf<int>, -inf<int>});
  rb_arr<PII> dat(vc<PII>(si(f), {inf<int>, -inf<int>}));
  int rs = 0, cp = 0;
  Z ad = [&](int i) {
    int x = a[i];
    Z [l, r] = dat[x];
    chmin(l, i), chmax(r, i);
    dat.set(x, {l, r});
    chmax(rs, max(i - l, r - i));
  };
  Z reset = [&]() { rs = 0, dat.reset(); };
  int t = 0;
  Z save = [&]() { t = dat.time(), cp = rs; };
  Z rb = [&]() { rs = cp, dat.rb(t); };
  vc<int> s(Q);
  mo_roll(q, ad, ad, reset, save, rb, [&](int i) { s[i] = rs; });
  for (int x : s) print(x);
}

int main() {
  Yorisou();
  return 0;
}