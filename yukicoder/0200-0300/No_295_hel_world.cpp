#include "YRS/all.hpp"
#include "YRS/string/run_length.hpp"

constexpr i128 in = 1ll << 62;

map<pair<ll, ll>, ll> mp;
i128 C(ll n, ll k) {
  if (mp.contains({n, k})) return mp[{n, k}];
  if (k < 0 or k > n) return 0;
  chmin(k, n - k);
  i128 x = 1;
  FOR(i, k) {
    x = x * (n - i) / (i + 1);
    if (x >= in) return mp[{n, k}] = in;
  }
  return mp[{n, k}] = x;
}

void Yorisou() {
  VEC(ll, a, 26);
  STR(s);
  int N = si(s);
  FOR(i, N) s[i] -= 'a';
  Z seg = run_length(s);
  for (Z [e, p] : seg) if ((a[e] -= p) < 0) return print(0);
  array<vc<ll>, 26> v;
  for (Z [e, p] : seg) v[e].ep(p);

  Z f = [&](vc<ll> a, ll n) -> i128 {
    if (a.empty()) return 1;
    if (n == 0) return 1;
    sort(a, greater());
    if (si(a) > 70) sh(a, 70);
    int sz = si(a);
    ll s = SUM<ll>(a);

    if (s >= 6 && n > 10000) return in;

    if (n <= 10000) {
      vc<ll> b(a);
      FOR(n) {
        int id = 0;
        FOR(i, 1, sz) {
          i128 ls = i128(b[i] + 1) * (b[id] - a[id] + 1);
          i128 rs = i128(b[id] + 1) * (b[i] - a[i] + 1);
          if (ls > rs) id = i;
        }
        ++b[id];
      }
      i128 rs = 1;
      FOR(i, sz) {
        rs *= C(b[i], a[i]);
        if (rs >= in) return in;
      }
      return rs;
    } else {
      i128 rs = 1;
      n += s;
      i128 aa = n / sz;
      vc<i128> p(sz);
      Z f = [&](Z &f, int id, i128 sm) -> void {
        if (id == sz) {
          if (sm != n) return;
          i128 x = 1;
          FOR(i, sz) {
            x *= C(p[i], a[i]);
            if (x >= in) return void(rs = in);
          }
          chmax(rs, x);
          return;
        }
        for (i128 x = aa - 4; x <= aa + 4; ++x) {
          p[id] = x;
          f(f, id + 1, sm + x);
        }
      };
      f(f, 0, 0);
      return rs;
    }
  };

  i128 ans = 1;
  FOR(i, 26) {
    ans *= f(v[i], a[i]);
    if (ans >= in) return print("hel");
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"