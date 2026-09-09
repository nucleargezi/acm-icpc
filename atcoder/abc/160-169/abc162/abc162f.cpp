#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/retsu.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  retsu<ll> f(N, 4, ine<ll> / 2);
  FOR(i, min(N, 4)) f[i][i] = a[i];
  FOR(i, N) FOR(k, 4) {
    FOR(j, 2, 5) if (i + j < N and k + j - 2 < 4) {
      int t = i + j, x = a[t];
      chmax(f[t][k + j - 2], f[i][k] + x);
    }
  }
  ll s = ine<ll>;
  FOR(d, 4) if (d < N) {
    FOR(i, 4) if (i + N / 2 * 2 - 1 + d == N) chmax(s, f[N - d - 1][i]);
  }
  print(s);
}

int main() { Yorisou(); }