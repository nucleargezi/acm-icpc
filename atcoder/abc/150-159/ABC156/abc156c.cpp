#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/fib_search.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  print(fib_search<ll>([&](ll t) -> ll {
    ll s = 0;
    for (ll x : a) s += (t - x) * (t - x);
    return s;
  }, QMIN(a), QMAX(a) + 1).fi);
}

int main() { Yorisou(); }