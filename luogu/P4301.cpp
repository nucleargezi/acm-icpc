#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/sp.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  sort(a, greater());
  sp<int> s;
  ll rs = 0;
  for (int x : a) if (s.add(x)) rs += x;
  print(SUM<ll>(a) - rs);
}

int main() {
  Yorisou();
  return 0;
}