#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/st/st_sp.hpp"
#include "YRS/al/m/add_pair.hpp"

using MX = Add_pair<int, i128>;
using DS = st_sp<MX, 1, 4, ll>;
constexpr ull L = 1'000'000'000'000'000'001ull;
void Yorisou() {
  LL(N, K);
  VEC(PLL, a, N);
  ll mn = L;
  for (var [l, r] : a) chmin(mn, r - l);
  vc<ull> v{4, 7};
  FOR(i, si(v)) {
    ull x = v[i];
    if (x * 10 + 4 < L) v.ep(x * 10 + 4);
    if (x * 10 + 7 < L) v.ep(x * 10 + 7);
  }
  int sz = si(v);

  vc<ll> I;
  vc<pair<int, i128>> f;
  for (var [l, r] : a) I.ep(l);
  sort(I);
  for (ll x : I) f.ep(1, x);
  DS sl(I, f);
  I.clear(), f.clear();
  for (var [l, r] : a) I.ep(r);
  sort(I);
  for (ll x : I) f.ep(1, x);
  DS sr(I, f);

  print(bina([&](ll n) -> bool {
    if (n == 0) return 1;
    FOR(i, sz - n + 1) {
      ll l = v[i], r = v[i + n - 1];
      if (r - l > mn) continue;
      Z [c, sm] = sl.prod(l, L);
      i128 s = sm - (i128)l * c;
      tie(c, sm) = sr.prod(0, r);
      s += (i128)r * c - sm;
      if (s <= K) return 1;
    }
    return 0;
  }, 0, sz + 1));
}

int main() {
  Yorisou();
  return 0;
}