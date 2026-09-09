#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/fps/f/bernoulli.hpp"

using T = M11;
void Yorisou() {
  INT(D, W);
  T n = 1;
  vc<T> f(D + 1, 1);
  FOR(i, W) {
    INT(p, a);
    T x = p, q = x.inv();
    n *= x.pow(a);
    FOR(k, D + 1) f[k] *= T(1) - q, q *= x;
  }
  Z b = bernoulli<T>(D);
  T ans = 0, t = n;
  FOR_R(i, D + 1) {
    ans += (i & 1 ? -b[i] : b[i]) * C(D + 1, i) * f[i] * t;
    t *= n;
  }
  print(ans * invs(D + 1));
}

int main() { Yorisou(); }