#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

void before() {}

// #define tests
using RE = double;
NAME MeIoN_is_UMP45() {
    INT(n);
    vector<pair<point<RE>, point<RE>>> ps(n);
    for (meion &e : ps) {
        REA(x, y, dx, dy, s);
        RE d{s / std::hypot(dx, dy)};
        dx *= d, dy *= d;
        e = {{x, y}, {dx, dy}};
    }
    RE ans{inf<RE>};
    constexpr RE eps = 1e-8;
    FOR(i, n) {
        FOR(k, i + 1, n) {
            RE cross = ps[i].second.det(ps[k].second);
            if (ABS(cross) < eps) {
                if (ABS((ps[i].first - ps[k].first).det(ps[i].second)) < eps) {
                    if (ps[i].second.x * ps[k].second.x < 0) {
                        RE t{(ps[i].first.x - ps[k].first.x) /
                             (ps[k].second.x - ps[i].second.x)};
                        if (t > 0) chmin(ans, t);
                    } else {
                        FOR(2) {
                            RE t {(ps[i].first.x - ps[k].first.x) /
                                  ps[k].second.x};
                            if (t > 0) chmin(ans, t);
                            std::swap(i, k);
                        }
                    }
                }
            } else {
                RE t1 = (ps[k].first.x * ps[k].second.y -
                         ps[k].first.y * ps[k].second.x -
                         ps[i].first.x * ps[k].second.y +
                         ps[i].first.y * ps[k].second.x) /
                        cross;
                RE t2 = (ps[i].first.x + ps[i].second.x * t1 - ps[k].first.x) /
                        ps[k].second.x;
                if (MIN(t1, t2) > -eps) chmin(ans, MAX(t1, t2));
            }
        }
    }
    if (ans == inf<RE>) iroha UL("No show :(");
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