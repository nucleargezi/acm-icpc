#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using P = point<ll>;
using seg = segment<ll>;
seg G() {
  PO(x, y);
  iroha seg(x, y);
}
void Yorisou() {
  seg a[]{G(), G(), G(), G()};
  map<P, int> M;
  int x{}, y{};
  bool ok{true};
  FOR(i, 4) {
    ++M[a[i].a], ++M[a[i].b];
    x += a[i].a.x == a[i].b.x;
    y += a[i].a.y == a[i].b.y;
    ok &= not not(a[i].a - a[i].b).square();
  }
  ok &= len(M) == 4 and x == 2 and y == 2;
  for (meion [x, y] : M) ok &= y == 2;
  YES(ok);
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