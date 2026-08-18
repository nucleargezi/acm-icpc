#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/mod/binom.hpp"

using T = M11;

vc<T> run(vc<PII> q) {
  int Q = si(q), N = 0;
  vc<char> r(Q);
  FOR(i, Q) {
    Z &[n, m] = q[i];
    chmin(m, n + 1);
    if (m > (n + 1) / 2) m = n + 1 - m, r[i] = 1;
    chmax(N, n);
  }
  binom<T> c;
  c.fac(N), c.ifac(N);
  vc<T> pw(N + 1, T(1)), a(Q);
  FOR(i, N) pw[i + 1] = pw[i] + pw[i];
  T s = 0, in = c.inv(2);
  Z C = [&](int n, int m) {
    return m < 0 or m > n ? T() : c.fa[n] * c.ifa[m] * c.ifa[n - m];
  };
  int n = 0, m = 0;
  FOR(i, Q) {
    Z [nn, mm] = q[i];
    while (n < nn) s = s + s - C(n, m - 1), ++n;
    while (n > nn) s += C(n - 1, m - 1), s *= in, --n;
    while (m < mm) s += C(n, m++);
    while (m > mm) s -= C(n, --m);
    a[i] = r[i] ? pw[n] - s : s;
  }
  return a;
}

void Yorisou() {
  INT(l, r, M);
  vc<PII> q(r - l + 1);
  FOR(i, l, r + 1) q[i - l] = {i, M + 1};
  for (Z x : run(q)) print(x);
}

int main() {
  Yorisou();
  return 0;
}