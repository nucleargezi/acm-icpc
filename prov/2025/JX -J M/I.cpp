#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/all.hpp"

#define tests
using RE = long double;
using P = point<RE>;
RE keis(RE d, RE a, RE t) {
  a = std::abs(a);
  if (a * t * t / 2 <= d) return a * t * t / 2;
  RE t0 = sqrtl(d * 2 / a);
  RE sb = std::floor(t / (t0 * 2));
  t = t - sb * t0 * 2;
  if (t >= t0) t = t0 + t0 - t;
  return a * t * t / 2;
}
void Yorisou() {
  P a, b, c, d, p;
  VEC(P, ps, 4);
  IN(p);
  REAL(T);

  ps = rearrange(ps, hull(ps));
  reverse(ps);
  while (not(ps[1].y >= ps[0].y and ps[1].y >= ps[2].y)) {
    std::rotate(ps.begin(), ps.begin() + 1, ps.end());
  }
  a = ps[0], b = ps[1], c = ps[2], d = ps[3];
  
  RE th = P::angle(a, b, b - P{0, 1'000'000});
  RE ht = P::angle(b - P{0, 1'000'000}, b, c);
  RE vl = 10 * std::cos(th), vr = 10 * std::sin(th);
  
  RE disl = keis(dist(line(a, d), p), vl, T);
  RE disr = keis(dist(line(c, d), p), vr, T);
  p += P(0, -1).rotate(-th) * disl;
  p += P(0, -1).rotate(ht) * disr;
  setp(10);
  print(p);
}
#include "YRS/Z_H/main.hpp"