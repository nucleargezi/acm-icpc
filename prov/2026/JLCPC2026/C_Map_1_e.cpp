#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using T = ull;
using X = pair<int, T>;
inline int sz = 1;
inline vc<T> pw{1};
constexpr T p = (1ull << 61) - 1, b = 10;
T ml(T a, T b) { return u128(a) * b % p; }
T ad(T a, T b) { return (a += b) >= p ? a - p : a; }

ll inv(ll xx) {
  ll x = xx, m = p;
  m = abs(m);
  x %= m;
  if (x < 0) x += m;
  ll a = x, b = m, u = 1, v = 0, t;
  while (b > 0) {
    t = a / b;
    swap(a -= t * b, b), swap(u -= t * v, v);
  }
  return u < 0 ? u + m : u;
}

void ee(int N) {
  while (sz < N) sz <<= 1;
  N = si(pw);
  pw.resize(sz);
  FOR(i, N, sz) pw[i] = ml(pw[i - 1], b);
}

T bs(int i) {
  if (i >= sz) ee(i + 1);
  return pw[i];
}

struct hash_t {
  int N;
  vc<T> a;
  
  hash_t(var s) {
    N = si(s);
    a.assign(N + 1, T());
    FOR(i, N) a[i + 1] = ad(ml(a[i], b), s[i]);
  }

  X operator()(int l, int r) const {
    assert(l <= r and r <= N and l <= r);
    int sz = r - l;
    return {sz, ad(a[r], p - ml(a[l], bs(sz)))};
  }
};

bool ck(const vc<int> &a, int d, int q) {
  int N = si(a);
  vc<int> c(d);
  FOR(i, N) c[i % d] += a[N - i - 1];
  int ca = 0, s = q;
  FOR(i, d) {
    int x = c[i] + ca, g = x % 10, n = (10 - s % 10) % 10;
    s = (s + n) / 10, ca = x / 10;
    if (g != n) return 0;
  }
  return ca == q - s;
}

void Yorisou() {
  STR(s);
  reverse(s);
  vc<int> f;
  for (char c : s) f.ep((c - '0') * 9);
  int N = si(f);
  FOR(i, N - 1) f[i + 1] += f[i] / 10, f[i] %= 10;
  if (f[N - 1] / 10) f.ep(f[N - 1] / 10), f[N - 1] %= 10, ++N;
  reverse(f);
  hash_t hs(f);

  FOR_R(d, 1, si(s) + 1) {
    ull s = 0;
    FOR(l, 0, N, d) {
      s = ad(s, hs(N - min(N, l + d), N - l).se);
    }
    ull g = (bs(d) + p - 1) % p, q = ml(s, inv(g));
    if (q and q <= (ull)ceil(N, d) and ck(f, d, q)) return print(d);
  }
  print(1);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}