#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
void Yorisou() {
  INT(N);
  VEC(P, a, N);
  a = rearrange(a, hull(a));
  N = len(a);
  RE ans = 0;
  FOR(i, N) {
    int k = (i + 1) % N;
    ans += dist(a[i], a[k]);
  }
  setp(2);
  UL(ans);
}
#include "YRS/Z_H/main.hpp"