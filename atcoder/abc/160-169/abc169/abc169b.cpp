#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  i128 s = 1;
  VEC(ll, a, N);
  if (count(all(a), 0)) return print(0);
  for (ll x : a) {
    s *= x;
    if (s > 1'000'000'000'000'000'000ll) return print(-1);
  }
  print(s);
}

int main() { Yorisou(); }