#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(x);
  ll rs = 1 + (x > 2);
  for (ll i = 2; i * i <= x; ++i) {
    ll s = i;
    if (x % i == 1) if (++rs; i * i != x - 1) ++rs;
    while (s < x + 1 and not(x % s)) rs += (x / s) % i == 1, s *= i;
  }
  print(rs);
}

int main() { Yorisou(); }