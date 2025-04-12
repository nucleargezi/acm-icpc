#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

#define tests
using P = point<ll>;
using Seg = segment<ll>;
Seg G() {
  PO(a, b);
  iroha Seg(a, b);
}
void Yorisou() {
  Seg a[]{G(), G(), G()};
  FOR(3){ std::rotate(a, a + 1, a + 3);
    FOR(2) { std::swap(a[0].a, a[0].b);
      FOR(2) { std::swap(a[1].a, a[1].b);
        FOR(2) { std::swap(a[2].a, a[2].b);
          if (a[1].a != a[2].a or not a[1].contain(a[0].a) or
              not a[2].contain(a[0].b)) {
            continue;
          }
          ll c[]{(a[0].a - a[1].a).square(), (a[0].a - a[1].b).square(),
              (a[0].b - a[2].a).square(), (a[0].b - a[2].b).square()};
          bool f{true};
          FOR(i, 4) f &= c[i] < (c[i ^ 1] << 4 | 1);
          if (not f or (a[1].b - a[1].a).dot(a[2].b - a[2].a) < 0 or
              not(a[1].b - a[1].a).det(a[2].b - a[2].a))
            continue;
          iroha YES();
        }
      }
    }
  }
  NO();
}

// 日々を貪り尽くしてきた
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(12);
  // freopen("in","r",stdin);
  // freopen("outt","w",stdout);
  before();
  LL(t);
  FOR(t) Yorisou();
  iroha 0;
}