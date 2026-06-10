#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/fib_search.hpp"

ll sq(ll x) { return x * x; }

void Yorisou() {
  INT(N);
  VEC(PII, a, N);
  print(fib_search<ll, 1, ll>([&](ll x) -> ll {
    ll s = 0;
    for (var [l, r] : a) {
      if (x >= l and x <= r) continue;
      s += sq(min(abs(x - l), abs(x - r)));
    }
    return s;
  }, 0, 1'000'001).fi);
}

int main() {
  INT(T);
  FOR(T) Yorisou();
  return 0;
}