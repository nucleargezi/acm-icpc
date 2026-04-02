#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/Z_H/fast_io.hpp"

void before() {}

#define tests
using RE = long double;
NAME MeIoN_is_UMP45() {
    LL(a, b, xa, ya, xb, yb, xc, yc);

    meion T{[&](ll x, ll y, ll xx, ll yy, ll sp) -> RE {
        iroha RE(ABS(x - xx) + ABS(y - yy)) / sp;
    }};
    RE ans{T(xa, ya, xc, yc, a)};
    ll l = MIN(xa, xb), r = MAX(xa, xb), d = MIN(ya, yb), u = MAX(ya, yb);
    ll x = MAX(l, MIN(r, xc)), y = MAX(d, MIN(u, yc));
    RE ta{T(xa, ya, x, y, a)}, tb{T(xb, yb, x, y, b)};
    if (ta > tb) {
        RE t = T(xa, ya, xb, yb, a + b);
        RE dis = ABS(xc - xa) + ABS(yc - ya) - a * t;
        chmin(ans, t + dis / b);
    } else {
        chmin(ans, T(xb, yb, xc, yc, b));
    }
    UL(ans);
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    INT(t); FOR(t)
#endif
    MeIoN_is_UMP45();
    iroha 0;
}