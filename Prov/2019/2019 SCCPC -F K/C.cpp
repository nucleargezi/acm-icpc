#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ds/monoid/affine.hpp"

#define tests
using RE = long double;
using PRR = pair<RE, RE>;
using mono = monoid_affine<RE>;
using X = mono::X;

int T = 0;
void Yorisou() {
  cout << std::format("Case {}:\n", ++T);
  INT(N, M);
  REAL(A, B);
  VEC(RE, x, N);
  VEC(PRR, g, M);
  sort(x);
  vector<RE> c = pre_sum(x);
  setp(6);
  Z keis = [&](X f) -> RE {
    if (f.first > 0) {
      if (mono::eval(f, x[0]) >= 0) return c[N] * f.FI + N * f.second;
      if (mono::eval(f, x[N - 1]) <= 0) return -c[N] * f.FI - N * f.second;
      int p = binary_search([&](int m) -> bool {
        return mono::eval(f, x[m]) < 0;
      }, 0, N);
      return -(f.FI * c[p + 1] + f.second * (p + 1)) + (f.FI * (c[N] - c[p + 1]) + f.SE * (N - p - 1));
    } else if (f.first < 0) {
      if (mono::eval(f, x[N - 1]) >= 0) return c[N] * f.FI + N * f.second;
      if (mono::eval(f, x[0]) <= 0) return -c[N] * f.FI - N * f.second;
      int p = binary_search([&](int m) -> bool {
        return mono::eval(f, x[m]) > 0;
      }, 0, N);
      return (f.FI * c[p + 1] + f.SE * (p + 1)) - (f.FI * (c[N] - c[p + 1]) + f.SE * (N - p - 1));
    }
    return std::abs(f.second) * N;
  };
  FOR(i, M) {
    X a = mono::op(X{A, B}, X{g[i].FI, g[i].SE});
    X b = mono::op(X{g[i].FI, g[i].SE}, X{A, B});
    a.FI -= 1;
    b.FI -= 1;
    print(keis(a) + keis(b));
  }
}
#include "YRS/Z_H/main.hpp"