#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  SV(s, '0');
  vector<ll> a{s.begin(), s.begin() + n}, b{s.begin() + n, s.end()};
  vector<ll> bs{1};
  while (len(bs) < n + 1) bs += bs.back() * 10;

  vector<PLL> va(n + 1, {-1, -1}), vb(va);
  FOR(msk, 1 << n) {
    ll x = 0, y = 0, e = n, f = n;
    FOR_R(i, n) {
      if (msk >> i & 1)
        x += a[n - i - 1] * bs[--e];
      else
        y += a[n - i - 1] * bs[--f];
    }
    chmax(va[popcount(msk)], PLL{x + y, msk});
  }

  FOR(msk, 1 << n) {
    ll x = 0, y = 0, e = 0, f = 0;
    FOR(i, n) {
      if (msk >> i & 1)
        x += b[n - i - 1] * bs[e++];
      else
        y += b[n - i - 1] * bs[f++];
    }
    chmax(vb[popcount(msk)], PLL{x + y, msk});
  }
  ll mx = -1, msk;
  FOR(L, n + 1) {
    ll R = n - L;
    if (chmax(mx, va[L].first + vb[R].first)) {
      msk = (va[L].second << n) | vb[R].second;
    }
  }
  string ans;
  FOR_R(i, n << 1) {
    ans += (msk >> i & 1) ? 'H' : 'M';
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"