#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N);
  ll s = SUM<ll>(a);
  vc<int> rs;
  FOR(i, N) {
    int x = a[i];
    if (x * N - x == s - x) rs.ep(i + 1);
  }
  print(si(rs));
  print(rs);
}

int main() {
  Yorisou();
  return 0;
}