#include "YRS/all.hpp"
#include "YRS/math/mod/modint.hpp"

using mint = M17;
void yorisou() {
  INT(N, K);
  VEC(ll, a, N);

  sort(all(a));
  int st = a[K - 1];
  int ed = a[N - K];
  int c = 0, d = 0;
  FOR(i, N) c += a[K - 1] == a[i];
  FOR(i, N) d += a[N - K] == a[i];
  ll f = 0, e = 0;
  FOR(i, K) f += a[i];
  FOR(i, K) e += a[N - i - 1];
  mint ans = 1;
  if (st == ed) {
    int cc = 0;
    FOR(i, K) cc += a[i] == a[K - 1];
    ans *= C<mint>(c, cc);
    c -= cc;
    cc = 0;
    FOR(i, K) cc += a[N - i - 1] == a[N - K];
    ans *= C<mint>(c, cc);
    if (a[0] == a[N - 1]) ans /= 2;
  } else {
    int cc = 0;
    FOR(i, K) cc += a[i] == a[K - 1];
    ans *= C<mint>(c, cc);
    cc = 0;
    FOR(i, K) cc += a[N - i - 1] == a[N - K];
    ans *= C<mint>(d, cc);
  }
  print(e - f, ans);
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T = 1;
  while (T--) yorisou();
  return 0;
}