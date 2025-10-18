#include "YRS/all.hpp"
#include "YRS/geo/4-closest_pair.hpp"
#include "YRS/geo/9-furthest_pair.hpp"
#include "YRS/random/rng.hpp"

// #define tests
using RE = long double;
using P = point<RE>;
void Yorisou() {
  std::cout << std::fixed << std::setprecision(2);
  INT(n);
  VEC(P, a, n);
  for (meion &[x, y] : a) {
    x += 1'000'000'000;
    y += 1'000'000'000;
  }
  meion [i, k] = furthest_pair(a);
  meion [I, K] = closest_pair2(a);
  UL((a[I] - a[K]).length(), (a[i] - a[k]).length());
}
#include "YRS/Z_H/main.hpp"