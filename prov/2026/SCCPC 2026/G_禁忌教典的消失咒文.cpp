#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  vc<ll> b(N), c(N);
  ll s = 0;
  FOR(i, N) {
    if (i & 1) s -= a[i];
    else s += a[i];
    b[i] = s;
  }
  s = 0;
  FOR_R(i, N) {
    if ((N - i) & 1) s += a[i];
    else s -= a[i];
    if ((N - i) & 1) c[i] = s;
    else c[i] = -s;
  }

  ll rs = K == 0;
  hashmap<int> d;
  FOR(i, 1, N) ++d[c[i]];
  FOR(i, N - 1) {
    ll f = b[i];
    --d[c[i + 1]];
    if (i & 1) rs += d.get(K - f, 0);
    else rs += d.get(f - K, 0);
  }
  FOR(i, N - 1) rs += b[i] == K;
  FOR(i, 1, N) rs += c[i] == K;
  print(rs);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}