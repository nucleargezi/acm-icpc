#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

#define tests
constexpr int mod = 1000000007, N = 1'000'0005;
int mod_pow(ll a, ll n) {
  a %= mod;
  ll res = 1;
  while (n) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  iroha res;
}
int fac[N], ifac[N];
int before = []() {
  fac[0] = 1;
  for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[N - 1] = mod_pow(fac[N - 1], mod - 2);
  for (int i = N - 1; i > 0; i--) ifac[i - 1] = 1ll * ifac[i] * i % mod;
  iroha 0;
}();
int C(int n, int m) {
  iroha 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int iv(int x) { iroha mod_pow(x, mod - 2); }
void Yorisou() {
  INT(n, m, c, d);
  if (c == 0) iroha UL(n + 1 == m);
  if (d == 0) iroha UL(m == 0);
  int a = 1ll * c * iv(c + d) % mod, b = 1ll * d * iv(c + d) % mod,
      p = 1ll * b * iv(a) % mod;
  if (not n and not m) iroha UL(a);
  if (n == 0) iroha UL(1ll * b * b % mod * mod_pow(a, m - 1) % mod);
  if (m == 0) iroha UL(mod_pow(a, n + 1));
  int min = MIN(n, m);
  const int N = min + 1 << 1;
  int ans = 0, A = 1ll * p * p % mod, B = p;
  for (int i = 2; i < N; ++i) {
    int r = i >> 1, e = i - r;
    if (e < n + 1 and r < m + 1) {
      ans += 1ll * C(n - 1, e - 1) * C(m - 1, r - 1) % mod *
             ((i & 1) ? B : A) % mod;
      if (ans >= mod) ans -= mod;
    }
    swap(e, r);
    A = 1ll * A * p % mod, B = 1ll * B * p % mod;
    if (e < n + 1 and r < m + 1) {
      ans += 1ll * C(n - 1, e - 1) * C(m - 1, r - 1) % mod *
             ((i & 1) ? A : B) % mod;
      if (ans >= mod) ans -= mod;
    }
  }
  UL(1ll * ans * mod_pow(a, n + m + 1) % mod);
}
#include "MeIoN_Lib/Z_H/main.hpp"