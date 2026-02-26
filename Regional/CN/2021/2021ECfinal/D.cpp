#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/all.hpp"

#define tests 1
#define fl 0
#define DB 10
using P = point<i128>;
using seg = segment<i128>;
i128 gcd(i128 x, i128 y) {
  return y ? gcd(y, x % y) : x;
}
T3<i128> nor(line<i128> l) {
  Z [a, b, c] = l;
  i128 g = gcd(a, gcd(b, c));
  if (not g) return {0, 0, 0};
  a /= g, b /= g, c /= g;
  if (a < 0 or (a == 0 and b < 0) or (a == 0 and b == 0 and c < 0)) 
    a = -a, b = -b, c = -c;
  return {a, b, c};
}
void Yorisou() {
  P s, t, a, b, c, d;
  IN(s, t, a, b, c, d);
  seg st(s, t), ab(a, b), cd(c, d);
  if (s == t) return print(0);
  if (not st.cross(ab, 1) and not st.cross(cd, 1)) return print(0);
  if (not ab.cross(cd, 0)) return print(1);
  if (ab.is_para(cd)) return print(1);

  if (not st.cross(ab, 0) or not st.cross(cd, 0)) return print(1);
  if (ab.contains(c) or ab.contains(d)) return print(1);
  if (cd.contains(a) or cd.contains(b)) return print(1);

  seg sa(s, a), sb(s, b), sc(s, c), sd(s, d);
  seg ta(t, a), tb(t, b), tc(t, c), td(t, d);
  Z ok = [&](seg s) -> bool {
    if (s.cross(ab, 0)) return 0;
    if (s.cross(cd, 0)) return 0;
    int f = 0;
    f += s.b == a;
    f += s.b == b and a != b;
    f += s.b == c;
    f += s.b == d and c != d;
    return f <= 1;
  };
  for (seg f : {sa, sb, sc, sd}) if (ok(f)) {
    for (seg g : {ta, tb, tc, td}) if (ok(g)) {
      seg ac = seg(f.b, g.b);
      if (ac.cross(ab, 0) or ac.cross(cd, 0)) continue;
      if (f.b == g.b) return print(1);
      if (not f.is_para(g)) {
        if (f.cross({g.b, g.b + f.a - g.a}, 1) or
            g.cross({f.b, f.b + g.a - f.a}, 1))
          return print(1);
      } else {
        if (nor(f.to_line()) == nor(g.to_line())) return print(1);
      }
    }
  }
  print(2);
}
#include "YRS/aa/main.hpp"