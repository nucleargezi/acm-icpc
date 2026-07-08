#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/pr/divisors.hpp"

void Yorisou() {
  INT(N);
  Z div = divisor(N);
  ll mn = inf<ll>, mx = -mn;
  for (ll x : div) for (ll y : div) if (N % (x * y) == 0) {
    chmin(mn, (x + 1) * (y + 2) * (N / x / y + 2));
    chmax(mx, (x + 1) * (y + 2) * (N / x / y + 2));
  }
  print(mn - N, mx - N);
}

int main() {
  Yorisou();
  return 0;
}