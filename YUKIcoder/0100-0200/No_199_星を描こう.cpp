#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/basic/hull.hpp"

using P = point<ll>;
void Yorisou() {
  VEC(P, a, 5);
  YES(len(hull(a)) == 5);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"