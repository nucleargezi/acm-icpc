#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  sort(a);
  vc<ll> c(all(a));
  c = pre_sum(c);
  int nd = K / 2 + 1, ls = K - nd;
  ll s = 0;
  FOR(i, ls, N - nd + 1) {
    ll x = a[i] + a[i + (~K & 1)];
    chmax(s, c[N] - c[ls] - (c[i + nd] - c[i]) + x * K / 2);
  }
  print(s);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}