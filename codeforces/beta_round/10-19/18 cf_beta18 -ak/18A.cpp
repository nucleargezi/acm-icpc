#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using P = point<ll>;
void Yorisou() {
  VEC(P, a, 3);
  meion f = [&]() -> bool {
    FOR(i, 3) FOR(k, i) if (a[i] == a[k]) iroha false;
    vector<P> v;
    FOR(i, 3) FOR(k, i) v += a[i] - a[k];
    FOR(i, 3) FOR(k, i) if (not v[i].dot(v[k])) iroha true;
    iroha false;
  };
  if (f()) iroha UL("RIGHT");
  constexpr int dx[]{1, -1, 0, 0}, dy[]{0, 0, 1, -1};
  FOR(i, 3) {
    FOR(k, 4) {
      a[i] += {dx[k], dy[k]};
      if (f()) iroha UL("ALMOST");
      a[i] -= {dx[k], dy[k]};
    }
  }
  UL("NEITHER");
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