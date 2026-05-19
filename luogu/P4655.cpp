#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/sl/cht.hpp"

void Yorisou() {
  INT(N);
  VEC(ll, h, N);
  VEC(ll, s, N);
  s = pre_sum(s);
  vc<ll> f(N);
  f[0] = 0;
  cht<ll, 0> g;
  g.add(-2 * h[0], f[0] + h[0] * h[0] - s[1]);
  FOR(i, 1, N) {
    f[i] = g(h[i]) + s[i] + h[i] * h[i];
    g.add(-2 * h[i], f[i] + h[i] * h[i] - s[i + 1]);
  }
  print(f[N - 1]);
}

int main() {
  Yorisou();
  return 0;
}