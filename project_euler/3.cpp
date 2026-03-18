#include "YRS/all.hpp"
#include "YRS/pr/factors.hpp"

void Yorisou() {
  vc<ll> t;
  for (Z [a, b] : factor(600851475143ll)) t.ep(a);
  print(QMAX(t));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"