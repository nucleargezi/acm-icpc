#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  vc<ll> a{4, 7};
  FOR(i, si(a)) {
    ll x = a[i];
    if (x * 10 + 4 <= N) a.ep(x * 10 + 4);
    if (x * 10 + 7 <= N) a.ep(x * 10 + 7);
  }
  for (int x : a) if (N % x == 0) return YES();
  NO();
}

int main() {
  Yorisou();
  return 0;
}