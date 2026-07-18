#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
constexpr re eps = 1e-8l;

void Yorisou() {
  vc<pair<re, re>> p;
  FOR(i, 55) {
    re the = i * (2 * pi / 55), R = 0.095l - eps;
    p.ep(R * sin(the), R * cos(the));
  }
  FOR(i, 45) {
    re the = i * (2 * pi / 45), R = 0.095l - eps - eps - 0.01;
    p.ep(R * sin(the), R * cos(the));
  }
  setp(20);
  INT(Q);
  FOR(Q) {
    INT(N);
    print(N << 1);
    vc<T3<re>> rs;
    FOR(i, N) {
      var [x, y] = p[i];
      rs.ep(x, y, 0.l);
      rs.ep(x, y, 0.99l + 1e-6l);
    }
    for (var [a, b, c] : rs) print(a, b, c);
  }
}

int main() {
  Yorisou();
  return 0;
}