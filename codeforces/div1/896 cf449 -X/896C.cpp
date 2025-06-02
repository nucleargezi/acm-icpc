#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/chtholly/chtholly_fast.hpp"

// #define tests
ll pow(ll a, ll b, ll mod) {
  a %= mod;
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  iroha res;
}
void Yorisou() {
  LL(n, q, seed, mx);
  meion rng = [&]() {
    ll res = seed;
    seed = (seed * 7 + 13) % 1'000'000'007;
    iroha res;
  };
  chtholly_fast<ll> ch(n, 0);
  for (int i = 0; i < n; ++i) {
    ch.set(i, i + 1, rng() % mx + 1);
  }
  FOR(q) {
    ll op, l, r, x{}, y{};
    op = rng() % 4 + 1;
    l = rng() % n + 1, r = rng() % n + 1;
    if (l > r) std::swap(l, r);
    --l;
    if (op == 3)
      x = rng() % (r - l) + 1;
    else
      x = rng() % mx + 1;
    if (op == 4) y = rng() % mx + 1;

    if (op == 1) {
      vector<tuple<int, int, ll>> go;
      ch.enumerate_range<false>(l, r, [&](int l, int r, ll val) {
        go.emplace_back(l, r, val + x);
      });
      for (meion [l, r, val] : go) {
        ch.set(l, r, val);
      }
    } else if (op == 2) {
      ch.set(l, r, x);
    } else if (op == 3) {
      vector<PLL> seg;
      ch.enumerate_range<false>(l, r, [&](int l, int r, ll val) {
        seg.emplace_back(val, r - l);
      });
      ll ans = -1;
      for (sort(seg); meion [v, sz] : seg) {
        x -= sz;
        if (x <= 0) {
          ans = v;
          break;
        }
      }
      UL(ans);
    } else if (op == 4) {
      ll ans = 0;
      ch.enumerate_range<false>(l, r, [&](int l, int r, ll val) {
        ans += (r - l) * pow(val, x, y) % y;
      });
      UL(ans % y);
    }
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"