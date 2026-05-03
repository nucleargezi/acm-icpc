#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/line/01/sp.hpp"

void Yorisou() {
  INT(N);
  using P = pair<ll, int>;
  VEC(P, a, N);
  sort(a, [&](var a, var b) { return a.se > b.se; });
  sp<ll> s;
  ll rs = 0;
  for (var [a, b] : a) if (s.add(a)) rs += b;
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}