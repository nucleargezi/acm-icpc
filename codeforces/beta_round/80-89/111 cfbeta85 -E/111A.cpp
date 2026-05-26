#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(N, x, y);
  vc<ll> a(N, 1);
  if (N > y) return print(-1);
  a[0] = 1 + y - N;
  ll s = 0;
  for (ll x : a) s += x * x;
  if (s < x) return print(-1);
  for (ll x : a) print(x);
}

int main() {
  Yorisou();
  return 0;
}