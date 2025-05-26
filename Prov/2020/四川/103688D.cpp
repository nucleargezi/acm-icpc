#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

#define tests
using RE = long double;
using P = point<ll>;
constexpr ll R = 1;
constexpr RE eps = 1e-9;
void Yorisou() {
  PO(a, b, c);
  b -= a, c -= a;
  meion del = pi / 2 - std::acos(2 / std::sqrt(b.square()));
  meion ang = b.angle();
  meion l = ang - del, r = ang + del;
  std::tie(l, r) = pair{r - pi / 2, l + pi / 2};
  c -= b;
  del = pi / 2 - std::acos(2 / std::sqrt(c.square()));
  ang = c.angle();
  meion L = ang - del, R = ang + del;
  if (L < eps) L += pi * 2, R += pi * 2;
  if (l < eps) l += pi * 2, r += pi * 2;
  bool f{L > r - eps or R < l + eps};
  l -= pi * 2, r -= pi * 2;
  f &= L > r - eps or R < l + eps;
  l += pi * 2, r += pi * 2;
  l += pi * 2, r += pi * 2;
  f &= L > r - eps or R < l + eps;
  no(f);
}
#include "MeIoN_Lib/Z_H/main.hpp"