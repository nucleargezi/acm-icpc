#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/ge/all.hpp"

// #define tests
using RE = double;
using P = point<RE>;
using T = tuple<P, RE, RE>;
bool check(P A, P B, RE v, RE w) {
  RE t = dist(A, B) / v;
  RE th = B.angle();
  th = std::min(th, std::numbers::pi * 2 - th);
  return t * w > th;
}
void Yorisou() {
  P st, ed;
  IN(st, ed);
  INT(N);
  VEC(T, a, N);
  INT(K);
  setp(4);
  print(binary_search_real<RE>([&](RE vi) -> bool {
    if (vi < 1e-5) return false;
    int hp = K + 1;
    for (Z [p, a, w] : a) {
      P A = st, B = ed;
      A -= p, B -= p;
      A = A.rotate(-a);
      B = B.rotate(-a);
      if (A.angle() > B.angle()) A.y = -A.y, B.y = -B.y;
      int atk = 0;
      if (check(A, B, vi, w)) atk = 1;
      P C = line(A, B).toei({});
      RE dis = C.length();
      if (dis * w  < vi) {
        RE t = sqrtl(vi / (dis * w) - 1);
        P g = {C.x + C.y * t, C.y - C.x * t};
        if ((A - g).dot(B - g) < 0 and check(A, g, vi, w)) atk = 1;
        g = {C.x - C.y * t, C.y + C.x * t};
        if ((A - g).dot(B - g) < 0 and check(A, g, vi, w)) atk = 1;
      }
      hp -= atk;
    }
    return hp > 0;
  }, inf<int>, 0));
}
#include "YRS/Z_H/main.hpp"