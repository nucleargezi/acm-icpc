#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

i128 f(ll l, ll r, ll d, ll lm) {
  r = min(r - 1, lm);
  if (l > r) return 0;
  i128 ls = l + l + (r - l) / d * d, rs = (r - l) / d + 1;
  return ls * rs;
}

i128 ke(ll l, ll r, ll sl, ll sr, ll d, ll ql, ll qr, ll C, ll D) {
  if (r <= ql or l >= qr or l >= r) return 0;
  if (ql <= l and r <= qr) return f(sl, sr, d, D) - f(sl, sr, d, C);
  ll m = (l + r) >> 1;
  if (m - l < r - m) ++m;
  return ke(l, m, sl, sr, d + d, ql, qr, C, D) +
         ke(m, r, sl + d, sr, d + d, ql, qr, C, D);
}

void Yorisou() {
  LL(N, Q, P);
  ++N;
  FOR(Q) {
    LL(l, r, c, d);
    ++r, --c;
    print(ke(1, N, 1, N, 1, l, r, c, d) / 2 % P);
  }
}

int main() {
  Yorisou();
  return 0;
}