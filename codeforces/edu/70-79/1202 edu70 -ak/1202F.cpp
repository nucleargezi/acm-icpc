#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
NAME MeIoN_is_UMP45() {
    int a, b;
    std::cin >> a >> b;
    int ans{};
    for (int l{1}, r, INF{inf<int>}; l < a + b + 1; l = r + 1) {
        r = inf<int> - 1;
        if (a / l) chmin(r, a / (a / l));
        if (b / l) chmin(r, b / (b / l));
        int la{(a - 1) / (r + 1)}, ra{a / r},
            lb{(b - 1) / (r + 1)}, rb{b / r},
            L{la + lb + 1}, R{MIN(ra + rb, INF)};
        if (la < ra and lb < rb) ans += MAX(0, R - L);
        chmin(INF, L);
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