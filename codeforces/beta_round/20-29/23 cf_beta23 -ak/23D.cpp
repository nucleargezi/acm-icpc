#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using RE = long double;
using P = point<RE>;
constexpr RE eps = 1e-9L;
bool f(P a, P b, P c, P d) {
  RE c1 = (b - a).det(c - b), c2 = (c - b).det(d - c), 
     c3 = (d - c).det(a - d), c4 = (a - d).det(b - a);
  if (c1 > 0 and c2 > 0 and c3 > 0 and c4 > 0) iroha true;
  if (c1 < 0 and c2 < 0 and c3 < 0 and c4 < 0) iroha true;
  iroha false;
}
void Yorisou() {
  VEC(P, a, 3);
  sort(a);
  do {
    meion [A, B, C] = tuple{a[0], a[1], a[2]};
    P x = B - A, y = C - B - B + A;
    RE det = x.det(y);
    if (det == 0) continue;
    RE c1 = x.square() / 2, c2 = -y.square() / 2;
    P u {y.y * c1 - x.y * c2, -y.x * c1 + x.x * c2};
    u /= det;
    P a = A - u, b = A + A - a, c = B + B - b, d = C + C - c;
    RE ab = (b - a).square(), bc = (c - b).square(), cd = (d - c).square();
    if (ABS(ab - bc) > eps or ABS(bc - cd) > eps) continue;
    if (not f(a, b, c, d)) continue;
    iroha YES(), UL(a, b, c, d);
  } while (std::next_permutation(a.begin(), a.end()));
  NO();
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
#ifdef tests
  LL(t); FOR(t)
#endif
  Yorisou();
  iroha 0;
}