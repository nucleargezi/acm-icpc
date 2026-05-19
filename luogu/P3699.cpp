#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/segment.hpp"

using re = ld;
using P = point<ll>;
using S = segment<ll>;
TE re dist(line<T> L, point<T> P) {
  return abs(L.eval(P)) / sqrtl(L.a * L.a + L.b * L.b);
}
void Yorisou() {
  INT(N, M);
  VEC(P, a, N);

  vc<T3<P>> tr;
  FOR(M) {
    P a, b, c;
    IN(a, b, c);
    tr.ep(a, b, c);
  }

  int s = 0;
  Z ke = [&](const P &a, const T3<P> &f) {
    re s = inf<re>;
    var [x, y, z] = f;
    chmin(s, dist(line(x, y), a));
    chmin(s, dist(line(y, z), a));
    chmin(s, dist(line(x, z), a));
    return s;
  };
  FOR(i, N) {
    sort(tr, [&](var l, var r) { return ke(a[i], l) < ke(a[i], r); });
    FOR(k, i + 1, N) {
      S ab(a[i], a[k]);
      bool ok = 1;
      re dist = sqrtl((a[i] - a[k]).sq());
      for (var tr : tr) {
        if (ke(a[i], tr) > dist) break;
        var [x, y, z] = tr;
        if (S(x, y).cross(ab, 1) or S(y, z).cross(ab, 1)) {
          ok = 0;
          break;
        }
      }
      s += ok;
    }
  }
  print(s);
}

int main() {
  Yorisou();
  return 0;
}