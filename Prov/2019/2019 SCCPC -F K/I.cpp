#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

#define tests
using RE = long double;
int T;
void Yorisou() {
  cout << std::format("Case {}: ", ++T);
  INT(N, V);
  VEC(RE, a, N);
  RE s = 0;
  FOR(i, N) s += sqrtl(a[i] / a[0]);
  s = V / s;
  RE ans = 0;
  FOR(i, N) ans += sqrtl(a[i] * a[0]);
  setp(6);
  print(ans / s);
}
#include "YRS/Z_H/main.hpp"