#include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/math/bigint/big.hpp"

#define tests
using big = bigint;
void Yorisou() {
  big a, b;
  IN(a, b);
  Z [q, r] = a.divmod(b);
  print(q, r);
}
#include "YRS/Z_H/main.hpp"