#include "YRS/Z_H/MeioN.hpp"
#include "YRS/MeIoN_all.hpp"
#include "YRS/geo/1-base.hpp"

#define tests
using P = point<ll>;
void Yorisou() {
  PO(a, b, c, d);
  ll x = a.x + b.x, y = a.y + b.y, xx = c.x + d.x, yy = c.y + d.y;
  UL(std::max(std::abs(x - xx), std::abs(y - yy)));
}
#include "YRS/Z_H/main.hpp"