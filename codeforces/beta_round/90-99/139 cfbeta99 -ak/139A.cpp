#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  LL(s);
  VEC(ll, a, 7);
  ll sm = SUM<ll>(a);
  s %= sm;
  if (s == 0) s += sm;
  FOR(i, 7) {
    s -= a[i];
    if (s <= 0) return print(i + 1);
  }
}

int main() {
  Yorisou();
  return 0;
}