#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

constexpr Z ten = []() {
  array<i128, 20> rs{1};
  FOR(i, 1, 20) rs[i] = rs[i - 1] * 10;
  return rs;
}();

int f(ll x) {
  int s = 0;
  for (--x; x > 0; x /= 10) s += !!(x % 10);
  return s;
}

ll f(ll x, int k) { return k <= 1 ? x : x / ten[k - 1]; }

void Yorisou() {
  LL(H, M, K);
  LL(h1, m1, h2, m2);
  ll s = h1 * M + m1, t = h2 * M + m2;

  Z ke = [&](ll h, ll hnd, ll hd) -> ll {
    return f(min(h, H - 1), hnd) + (h == H and hd >= hnd);
  };
  Z ge = [&](ll x) -> ll {
    ll a = x / M, b = x % M;
    return a * f(M - 1, K) + ke(a, K - f(M), f(H)) + f(b, K);
  };
  ll rs = ge(t) - ge(s);
  if (s > t) rs += ge(H * M);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}