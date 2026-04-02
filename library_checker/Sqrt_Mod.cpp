#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/math/mod/mod_sqrt.hpp"

#define tests
void Yorisou() {
  LL(x, p);
  ll r = mod_sqrt(x, p);
  UL(r * r % p == x ? r : -1);
}
#include "YRS/Z_H/main.hpp"