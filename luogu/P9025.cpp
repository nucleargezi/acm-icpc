#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/nt/fib_search.hpp"

void Yorisou() {
  INT(N);
  VEC(T3<ll>, a, N);
  print(fib_search<ll, 1, int>([&](int x) -> ll {
    ll s = 0;
    for (var [p, w, d] : a) {
      s += max(0ll, abs(p - x) - d) * w;
    }
    return s;
  }, 0, 1'000'000'001).fi);
}

int main() {
  Yorisou();
  return 0;
}