#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
using RE = long double;
struct point {
  RE x, y, z;
};
RE dot(point a, point b) {
  iroha a.x * b.x + a.y * b.y + a.z * b.z;
}
void Yorisou() {
  RE r, d;
  point s, t;
  IN(r, d, s.x, s.y, s.z, t.x, t.y, t.z);
  RE the = d / r, alp = dot(s, t);
  alp /= std::sqrt(dot(s, s));
  alp /= std::sqrt(dot(t, t));
  alp = std::acos(alp);
  RE ans;
  if (the >= pi or the + alp * 0.5 >= pi) {
    ans = 4 * pi * r * r;
  } else if (the <= pi * 0.5) {
    ans = (1 - std::cos(the)) * 2 * pi * r * r;
    ans += 2 * std::sin(the) * alp * r * r;
  } else {
    the = pi - the;
    alp *= 0.5;
    static constexpr int N = 750;
    RE cos = std::cos(the), spl = (the - alp) / N;
    for (int i = 1; i < N * 2; i += 2) {
      RE del = (alp * (N * 2 - i) + the * i) / (N * 2);
      RE t = cos / std::cos(del);
      ans += std::sqrt(1 - t * t) * spl;
    }
    ans = 4 * pi - ans * 4;
    ans *= r * r;
  }
  print("{:.18f}", ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"