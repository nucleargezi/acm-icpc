#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/math/PR/divisors.hpp"

// #define tests
void Yorisou() {
  INT(a, b);
  vector v = sorted(divisor(std::gcd(a, b)));
  v.insert(v.begin(), -1);
  INT(N);
  FOR(N) {
    INT(l, r);
    int x = v[upper_bound(v, r) - 1];
    print(x >= l ? x : -1);
  }
}
#include "YRS/Z_H/main.hpp"