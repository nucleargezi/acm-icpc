#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/bigint/big.hpp"
#include "YRS/nt/fib.hpp"

void Yorisou() {
  LL(N);
  if (N == 2) return print(3), print("INF");
  using ll = bigint;
  ll x = fibonacci<ll>{}(N);
  if ((N & 1) == 0) {
    ll d = fibonacci<ll>{}(N >> 1);
    x -= d * d;
  }
  print(N);
  print(x);
}

int main() {
  Yorisou();
  return 0;
}