#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

void Yorisou() {
  INT(N);
  VEC(T3<ll>, a, N);
  INT(M);
  VEC(T3<ll>, b, M);
  ll s = 0;
  for (var [n, m, h] : a) {
    ll g = inf<ll>;
    for (var [b, a, c] : b) if (b >= h) {
      ll d = b / h;
      chmin(g, ceil(n + n + m + m, d * a) * c);
    }
    s += g;
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}