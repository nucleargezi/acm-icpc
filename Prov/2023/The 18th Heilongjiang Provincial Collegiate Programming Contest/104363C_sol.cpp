#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint_d.hpp"
void before() {}

#define tests
NAME MeIoN_is_UMP45() {
    array<int, 3> x, y;
    std::cin >> x >> y;
    vector<int> min(y[0], inf<int> / 4);
    for (int i{}; i < y[0]; ++i) {
        for (int k{}; k < y[0]; ++k) {
            chmin(min[(i * y[1] + k * y[2]) % y[0]], i * y[1] + k * y[2]);
        }
    }
    int ans{inf<int> / 4};
    for (int i{}, E{LCM(y[1], y[2])}; i < E; ++i) {
        int r{};
        dmint::set_mod(y[2]);
        r += dmint(-(i + x[2])).val;
        dmint::set_mod(y[1]);
        r += dmint(-(i + x[1])).val;
        dmint::set_mod(y[0]);
        int z{dmint(-(x[0] + r)).val};
        chmin(ans, i + min[z] + r);
    }
    std::cout << (ans == inf<int> / 4 ? -1 : ans) << '\n';
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