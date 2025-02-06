#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/ds/seg/seg_base.hpp"
#include "MeIoN_Lib/ds/monoid/add.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"

void before() {}

// #define tests
using mint = modint<mod99>;
NAME MeIoN_is_UMP45() {
    int n;
    std::cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    meion dis = [&](vector<int> &v) -> void {
        vector un(v);
        unique(un);
        for (meion &x : v) x = int(lower(un, x) - un.begin());
    };
    dis(x), dis(y);
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        points[i] = {x[i], y[i]};
    }
    sort(points);
    vector<mint> power(0721 << 10);
    power[0] = 1;
    for (int i = 1; i < (0721 << 10); ++i) {
        power[i] = power[i - 1] * 2;
    }
    mint ans;
    Seg<monoid_add<int>> g(n);
    for (int i = 0, x, y; i < n; ++i) {
        std::tie(x, y) = points[i];
        int s = g.prod(0, y);
        g.apply(y, 1);
        ans += (power[n] - power[n - y - 1] - power[y] - power[i] -
                power[n - i - 1] + power[s] + power[y - s] + power[i - s] +
                power[n - y - 1 - i + s] - 1);
    }
    std::cout << ans << '\n';
}

// 日々を貪り尽くしてきた
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    // freopen("in","r",stdin);
    // freopen("outt","w",stdout);
    before();
#ifdef tests
    std::cin >> T;
#endif
    while (T--) { MeIoN_is_UMP45(); }
    iroha 0;
}