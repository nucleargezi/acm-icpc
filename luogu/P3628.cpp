#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/sl/cht.hpp"

void Yorisou() {
  INT(N, a, b, c);
  VEC(ll, s, N);
  s = pre_sum(s);
  cht<ll, 1> g;
  g.add(0, 0);
  vc<ll> f(N + 1);
  FOR(i, 1, N + 1) {
    f[i] = g(s[i]) + a * s[i] * s[i] + b * s[i] + c;
    g.add(-2 * a * s[i], f[i] + a * s[i] * s[i] - b * s[i]);
  }
  print(f[N]);
}

int main() {
  Yorisou();
  return 0;
}