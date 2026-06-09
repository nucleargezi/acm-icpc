#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ge/basic/bs3.hpp"
#include "YRS/ge/exp/minimum_enclosing_circle.hpp"

using re = ld;
using PP = p3<re>;
using P = point<re>;
void Yorisou() {
  INT(N, Q);
  VEC(PP, p, N);
  FOR(Q) {
    REAL(a, b, c);
    PP n{a, b, c}, d{b, -a, 0};
    if (a == 0 and b == 0) d = {c, 0, -a};
    PP dd = n.det(d);
    d /= d.length();
    dd /= dd.length();
    vc<P> s(N);
    FOR(i, N) s[i] = {d.dot(p[i]), dd.dot(p[i])};
    Z [O, i, k, j] = minimum_enclosing_circle<re, 1e-12l>(s);
    print(O.R);
  }
}

int main() {
  Yorisou();
  return 0;
}