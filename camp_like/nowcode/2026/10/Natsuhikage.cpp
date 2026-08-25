#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/point.hpp"
#include "YRS/ge/basic/line.hpp"

using re = ld;
using P = point<ll>;
void Yorisou() {
  P s, a, b;
  IN(s, a, b);
  Z ke = [&](P p) { return abs((re)(p.det(s)) / s.y); };
  re ls = min(ke(a), ke(b)), rs = max(ke(a), ke(b));
  if (a.det(s) >= 0 and s.det(b) >= 0) ls = 0;
  if (s.x > 0) {
    P g{-s.y, s.x};
    if (a.det(g) >= 0 and g.det(b) >= 0) rs = a.length() * s.length() / s.y;
  } else if (s.x < 0) {
    P g{s.y, -s.x};
    if (a.det(g) >= 0 and g.det(b) >= 0) rs = a.length() * s.length() / s.y;
  }
  print(ls, rs);
}

int main() {
  setp(15);
  INT(T);
  FOR(T) Yorisou();
}