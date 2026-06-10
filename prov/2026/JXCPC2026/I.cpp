#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N, d);
  VEC(int, w, 3);
  STR(s);
  FOR(i, N) s[i] -= '0';
  retsu<ll> f(N + 1, 4, inf<ll>);
  f[0][3] = 0;
  FOR(i, N) {
    FOR(k, 1, 4) if (f[i][k] != inf<ll>) {
      chmin(f[min(N, i + d)][k - 1], f[i][k]);
    }
    FOR(k, 4) if (f[i][k] != inf<ll>) {
      chmin(f[i + 1][k], f[i][k] + w[s[i]]);
    }
  }
  ll rs = inf<ll>;
  FOR(k, 4) chmin(rs, f[N][k]);
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}