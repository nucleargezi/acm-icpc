#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"

using re = ld;
re sq(re x) { return x * x; }
void Yorisou() {
  INT(N);
  VEC(T3<int>, a, N);
  re xx = 0, yy = 0, zz = 0, p = 1;
  FOR(1000000) {
    p *= 0.999;
    int id = 0;
    re mx = -1;
    FOR(i, N) {
      var [x, y, z] = a[i];
      if (chmax(mx, sq(xx - x) + sq(yy - y) + sq(zz - z))) id = i;
    }
    Z [x, y, z] = a[id];
    xx += (x - xx) * p;
    yy += (y - yy) * p;
    zz += (z - zz) * p;
  }
  print(xx, yy, zz);
}

int main() {
  Yorisou();
  return 0;
}